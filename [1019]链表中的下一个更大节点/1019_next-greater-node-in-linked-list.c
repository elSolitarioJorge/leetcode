int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    int size = 0;
    int vals[10000] = {0};
    struct ListNode* cur = head;
    while (cur) {
        vals[size++] = cur->val;
        cur = cur->next;
    }
    int* ans = (int*)malloc(size * sizeof(int));
    memset(ans, 0, size * sizeof(int));
    *returnSize = size;
    int stack[size];
    int top = -1;
    for (int i = 0; i < size; i++) {
        while (top >= 0 && vals[i] > vals[stack[top]]) {
            ans[stack[top--]] = vals[i];
        }
        stack[++top] = i;
    }
    return ans;
}
    
    