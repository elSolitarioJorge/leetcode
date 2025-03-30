struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* slow = dummyHead;
    struct ListNode* fast = dummyHead;
    for(int i = 0; i < n + 1; i++){
        if(fast == NULL){
            return head;
        }
        fast = fast->next;
    }
    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode* del = slow->next;
    slow->next = del->next;
    free(del);
    return dummyHead->next;
}
    
    