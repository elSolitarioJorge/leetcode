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
    
    