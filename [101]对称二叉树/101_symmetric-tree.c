bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL || q == NULL){
        return p == q;
    }
    return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    return isSameTree(root->left, root->right);
}
    
    