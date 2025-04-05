struct ListNode* deleteDuplicates(struct ListNode* head) {
    typedef struct ListNode Node;
    Node* hummyHead = (Node*)malloc(sizeof(Node));
    hummyHead->next = head;
    Node* pre = hummyHead;
    Node* cur = head;
    Node* temp;
    int flag = 0;
    while(cur){
        if(cur->next && cur->next->val == cur->val){
            flag = 1;
            temp = cur->next;
            cur->next = temp->next;
            free(temp);
        } else {
            if(flag){
                temp = cur;
                cur = cur->next;
                pre->next = cur;
                flag = 0;
                free(temp);
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
    }
    head = hummyHead->next;
    free(hummyHead);
    return head;
}

    
    