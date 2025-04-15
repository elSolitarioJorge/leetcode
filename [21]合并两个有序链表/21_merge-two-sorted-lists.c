//递归
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    if (list1->val > list2->val) {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
}
// 迭代
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummyHead;
    dummyHead.next = NULL;
    struct ListNode* cur = &dummyHead;
    struct ListNode* cur1 = list1;
    struct ListNode* cur2 = list2;
    while (cur1 && cur2) {
        if (cur1->val > cur2->val) {
            cur->next = cur2;
            cur2 = cur2->next;
        } else {
            cur->next = cur1;
            cur1 = cur1->next;
        }
        cur = cur->next;
    }
    if (cur1) {
        cur->next = cur1;
    } else {
        cur->next = cur2;
    }
    return dummyHead.next;
}
    
    