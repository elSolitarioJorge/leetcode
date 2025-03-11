#define MAX(a, b) ((a > b) ? (a) : (b))
int getHeight(struct TreeNode* node){
    if(node == NULL) return 0;
    int leftHeight = getHeight(node->left);
    if(leftHeight == -1){
        return -1;
    }
    int rightHeight = getHeight(node->right);
    if(rightHeight == -1 || abs(leftHeight - rightHeight) > 1){
        return -1;
    }
    return MAX(leftHeight, rightHeight) + 1;
}
bool isBalanced(struct TreeNode* root) {
    return getHeight(root) != -1;
}
    
    