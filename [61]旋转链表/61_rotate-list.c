struct ListNode* findNodeFS(struct ListNode* head, int k){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    for(int i = 0; i < k; i++){
        if(fast == NULL){
            return NULL;
        }
        fast = fast->next;
    }
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    int len = 0;
    struct ListNode* tail = head;
    while(tail && tail->next){
        len++;
        tail = tail->next;
    }
    len += 1;
    int n = k % len;
    struct ListNode* p = findNodeFS(head, n + 1);
    tail->next = head;
    head = p->next;
    p->next = NULL;
    return head;
}

    
    