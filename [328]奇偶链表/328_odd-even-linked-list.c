struct ListNode* oddEvenList(struct ListNode* head) {
    if(head == NULL || head->next == NULL || head->next->next == NULL){
        return head;
    }
    struct ListNode* pre = head;
    struct ListNode* cur = pre->next;
    struct ListNode* next = cur->next;
    while(next){
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
        pre = pre->next;
        cur = cur->next;
        if(cur == NULL){
            return head;
        }
        next = cur->next;
    }
    return head;
}
    
    