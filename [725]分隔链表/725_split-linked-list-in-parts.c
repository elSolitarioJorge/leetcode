struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    struct ListNode** ans = (struct ListNode**)malloc(sizeof(struct ListNode*) * k);
    for(int i = 0; i < k; i++){
        ans[i] = (struct ListNode*)malloc(sizeof(struct ListNode));
    }
    int len = 0;
    struct ListNode* cur = head;
    while(cur){
        len++;
        cur = cur->next;
    }
    cur = head;
    if(len <= k){
        for(int i = 0; i < k; i++){
            if(cur){
                ans[i] = cur;
                struct ListNode* next = cur->next;
                cur->next = NULL;
                cur = next;
            } else {
                ans[i] = NULL;
            }
        }
    } else {
        int a = len / k;
        int b = len % k;
        for(int i = 0; i < k; i++){
            ans[i] = cur;
            for(int j = 0; j < a - 1; j++){
                cur = cur->next;
            }
            if(b){
                cur = cur->next;
                b--;
            }
            struct ListNode* next = cur->next;
            cur->next = NULL;
            cur = next;
        }
    }
    *returnSize = k;
    return ans;
}

    
    