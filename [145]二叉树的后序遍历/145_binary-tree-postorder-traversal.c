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
    
    