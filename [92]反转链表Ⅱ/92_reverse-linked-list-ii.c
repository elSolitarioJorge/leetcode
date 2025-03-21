struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    typedef struct ListNode Node;
    Node* dummyHead = (Node*)malloc(sizeof(Node));
    dummyHead->next = head;
    Node* pre = dummyHead;
    for(int i = 0; i < left - 1; i++){
        pre = pre->next;
    }
    Node* cur = pre->next;
    Node* next = cur->next;
    for(int i = 0; i < right - left; i++){
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
        next = cur->next;
    }
    head = dummyHead->next;
    free(dummyHead);
    return head;
}
    
    