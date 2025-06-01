class Solution {
    private int res;
    public int sumNumbers(TreeNode root) {
        dfs(root, 0);
        return res;
    }

    private void dfs(TreeNode node, int x) {
        if (node == null) {
            return;
        }

        x = x * 10 + node.val;
        if (node.left == node.right) {
            res += x;
            return;
        }
        dfs(node.left, x);
        dfs(node.right, x);
    }
}
    
    