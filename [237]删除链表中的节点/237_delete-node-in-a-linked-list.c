void deleteNode(struct ListNode* node) {
    struct ListNode* cur = node;
    struct ListNode* pre;
    while(cur->next->next){
        cur->val = cur->next->val;
        cur = cur->next;
    }
    cur->val = cur->next->val;
    free(cur->next);
    cur->next = NULL;
}
    
    