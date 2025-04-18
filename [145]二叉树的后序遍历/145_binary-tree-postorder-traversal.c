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

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    if(root == NULL){
        return ans;
    }
    struct TreeNode* stack[100];
    struct TreeNode* node = root;
    struct TreeNode* pre = NULL;    // 用于记录上次访问的结点
    int top = -1;
    while(top >= 0 || node != NULL){
        while(node != NULL){
            stack[++top] = node;
            node = node->left;
        }
        node = stack[top--];
        if(node->right == NULL || pre == node->right){ // 右子结点为NULL或上次访问的是当前结点右子结点
            ans[(*returnSize)++] = node->val;  // 访问当前结点
            pre = node;    // 更新上次访问的结点
            node = NULL;
        } else{   //右子结点还有未被访问的结点
            stack[++top] = node;
            node = node->right;
        }
    }
    return ans;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
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
            stack[++top] = node;
            stack[++top] = NULL;
            if (node->right) {
                stack[++top] = node->right;
            }
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
    
    