struct ListNode* middleNode(struct ListNode* head) {
    typedef struct ListNode Node;
    int len = 0;
    Node* p = head;
    while(p){
        len++;
        p = p->next;
    }
    p = head;
    for(int i = 1; i < len/2 + 1; i++){
        p = p->next;
    }
    return p;
}
    
    