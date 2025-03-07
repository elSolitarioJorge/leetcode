void postorder(struct TreeNode* root, int* ans, int* returnSize){
    if(root == NULL){
        return;
    }
    postorder(root->left, ans, returnSize);
    postorder(root->right, ans, returnSize);
    ans[(*returnSize)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    postorder(root, ans, returnSize);
    return ans;
}
    
    