struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* cur = dummyHead;
    struct ListNode* temp1;
    struct ListNode* temp2;
    while(cur->next != NULL && cur->next->next != NULL){
        temp1 = cur->next;
        temp2 = cur->next->next->next;
        cur->next = cur->next->next;
        cur->next->next = temp1;
        cur->next->next->next = temp2;
        cur = cur->next->next;
    }
    return dummyHead->next;
}
    
    