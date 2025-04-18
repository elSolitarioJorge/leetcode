void inorder(struct TreeNode* root, int* ans, int* returnSize){
    if(root == NULL){
        return;
    }
    inorder(root->left, ans, returnSize);
    ans[(*returnSize)++] = root->val;
    inorder(root->right, ans, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    inorder(root, ans, returnSize);
    return ans;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
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
            stack[++top] = node;
            node = node->left;
        }
        node = stack[top--];
        ans[(*returnSize)++] = node->val;
        node = node->right;
    }
    return ans;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    if (root == NULL) {
        return ans;
    }
    struct TreeNode* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct TreeNode* node = stack[top--];
        if (node) {
            if (node->right) {
                stack[++top] = node->right;
            }
            stack[++top] = node;
            stack[++top] = NULL;
            if (node->left) {
                stack[++top] = node->left;
            }
        } else {
            node = stack[top--];
            ans[(*returnSize)++] = node->val;
        }
    }
    return ans;
}
    
    