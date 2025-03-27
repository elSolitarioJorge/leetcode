struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode* fast = dummyHead;
    struct ListNode* slow = dummyHead;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            int count = 1;
            struct ListNode* p = fast;
            while(fast->next != slow){
                count++;
                fast = fast->next;
            }
            fast = dummyHead;
            slow = dummyHead;
            for(int i = 0; i < count; i++){
                fast = fast->next;
            }
            while(fast != slow){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    free(dummyHead);
    return NULL;
}
    
    