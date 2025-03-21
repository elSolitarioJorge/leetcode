bool isValidBSTHelper(struct TreeNode* node, long lower, long upper){
    if(node == NULL) return true;
    if(node->val <= lower || node->val >= upper){
        return false;
    }
    return isValidBSTHelper(node->left, lower, node->val) && isValidBSTHelper(node->right, node->val, upper);
}
bool isValidBST(struct TreeNode* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}
    
    