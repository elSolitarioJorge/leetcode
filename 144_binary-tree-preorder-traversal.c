void preorder(struct TreeNode* root, int* ans, int* returnSize){
    if(root == NULL){
        return;
    }
    ans[(*returnSize)++] = root->val;
    preorder(root->left, ans, returnSize);
    preorder(root->right, ans, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    preorder(root, ans, returnSize);
    return ans;
}
    
    