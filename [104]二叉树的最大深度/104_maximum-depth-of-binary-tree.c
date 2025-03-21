#define MAX(a, b) ((a > b) ? (a) : (b))
int maxDepth(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return MAX(leftDepth, rightDepth) + 1;
}
    
    