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

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
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
            if (node->left) {
                stack[++top] = node->left;
            }
            stack[++top] = node;
            stack[++top] = NULL;
        } else {
            node = stack[top--];
            ans[(*returnSize)++] = node->val;
        }
    }
    return ans;
}
    
    