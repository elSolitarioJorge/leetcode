struct ListNode* removeElements(struct ListNode* head, int val) {
    typedef struct ListNode Node;
    Node* dummyHead = (Node*)malloc(sizeof(Node));
    dummyHead->next = head;
    Node* cur = dummyHead;
    while(cur->next){
        if(cur->next->val == val){
            Node* del = cur->next;
            cur->next = del->next;
            free(del);
        }
        else{
            cur = cur->next;
        }
    }
    head = dummyHead->next;
    free(dummyHead);
    return head;
}
    
    