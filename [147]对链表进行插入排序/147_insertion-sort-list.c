struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* cur = head->next;
    struct ListNode* pre = head;
    while(cur){
        if(cur->val < pre->val){
            struct ListNode* temp = dummyHead;
            while(temp->next->val <= cur->val){
                temp = temp->next;
            }
            pre->next = cur->next;
            cur->next = temp->next;
            temp->next = cur;
            cur = pre->next;
        } else {
            cur = cur->next;
            pre = pre->next;
        }
    }
    head = dummyHead->next;
    free(dummyHead);
    return head;
}
    
    