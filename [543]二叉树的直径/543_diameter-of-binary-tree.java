class Solution {
    private int ans;

    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return -1;
        }
        int left = dfs(root.left) + 1;
        int right = dfs(root.right) + 1;
        ans = Math.max(ans, left + right);
        return Math.max(left, right);
    }
}
    
    