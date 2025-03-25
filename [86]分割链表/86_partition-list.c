struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = -1;
    dummyHead->next = head;
    struct ListNode* pre = dummyHead;
    struct ListNode* cur = head;
    while(cur && cur->val < x){
        pre = cur;
        cur = cur->next;
    }
    while(cur && cur->next){
        if(cur->next->val < x){
            struct ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
            pre = pre->next;
        } else {
            cur = cur->next;
        }
    }
    head = dummyHead->next;
    free(dummyHead);
    return head;
}
    
    