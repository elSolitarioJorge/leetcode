struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* pre = head;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;
    return slow;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* cur = &dummy;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            cur->next = list1;
            list1 = list1->next;
        } else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    if (list1) {
        cur->next = list1;
    } else {
        cur->next = list2;
    }
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* head2 = middleNode(head);
    head = sortList(head);
    head2 = sortList(head2);
    return mergeTwoLists(head, head2);
}
    
    