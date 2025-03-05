struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* dummyHead = &dummy;
    struct ListNode* cur = head;
    while(cur){
        struct ListNode* temp = cur->next;
        cur->next = dummyHead->next;
        dummyHead->next = cur;
        cur = temp;
    }
    return dummy.next;
}
    
    