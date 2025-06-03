struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    while(cur){
        struct ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}
void reorderList(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast && fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode* curA = head;
    struct ListNode* curB = reverseList(slow->next);
    slow->next = NULL;
    int count = 0;
    struct ListNode* cur = head;
    while(curA && curB){
        if(count % 2 == 0){
            curA = curA->next;
            cur->next = curB;
        } else {
            curB = curB->next;
            cur->next = curA;
        }
        count++;
        cur = cur->next;
    }
}
    
    