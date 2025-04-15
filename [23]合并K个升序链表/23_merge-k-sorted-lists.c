struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummyHead;
    dummyHead.next = NULL;
    struct ListNode* cur = &dummyHead;
    while (list1 && list2) {
        if (list1->val > list2->val) {
            cur->next = list2;
            list2 = list2->next;
        } else {
            cur->next = list1;
            list1 = list1->next;
        }
        cur = cur->next;
    }
    if (list1) {
        cur->next = list1;
    } else{
        cur->next = list2;
    }
    return dummyHead.next;
}

struct ListNode* split(struct ListNode** lists, int l, int r) {
    int m = r - l;
    if (m == 0) {
        return NULL;
    }
    if (m == 1) {
        return lists[l];
    }
    struct ListNode* left = split(lists, l, l + m / 2);
    struct ListNode* right = split(lists, l + m / 2, r);
    return mergeTwoLists(left, right);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    return split(lists, 0, listsSize);
}


    
    