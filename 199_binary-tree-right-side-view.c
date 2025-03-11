void dfs(struct TreeNode* node, int* returnSize, int* ans, int depth){
    if(node == NULL){
        return;
    }
    if(depth == *returnSize){
        ans[(*returnSize)++] = node->val;
    }
    dfs(node->right, returnSize, ans, depth + 1);
    dfs(node->left, returnSize, ans, depth + 1);
}
int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    dfs(root, returnSize, ans, 0);
    return ans;
}
    
    