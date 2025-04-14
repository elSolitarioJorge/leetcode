int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftH = 0, rightH = 0;
    struct TreeNode* leftNode = root->left;
    struct TreeNode* rightNode = root->right;
    while (leftNode) {
        leftNode = leftNode->left;
        leftH++;
    }
    while (rightNode) {
        rightNode = rightNode->right;
        rightH++;
    }
    if (leftH == rightH) {
        return (2 << leftH) - 1;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}
    
    