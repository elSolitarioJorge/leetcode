int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    if(root == NULL){
        return ans;
    }
    struct TreeNode* stack[100];
    struct TreeNode* node = root;
    int top = -1;
    while(top >= 0 || node != NULL){
        while(node != NULL){
            ans[(*returnSize)++] = node->val;
            stack[++top] = node;
            node = node->left;
        }
        node = stack[top--];
        node = node->right;
    }
    return ans;
}
    
    