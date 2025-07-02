class Solution {
    private int res = Integer.MAX_VALUE;
    private TreeNode pre;

    public int getMinimumDifference(TreeNode root) {
        dfs(root);
        return res;
    }

    private void dfs(TreeNode node) {
        if (node == null) {
            return;
        }
        dfs(node.left);
        if (pre != null) {
            res = Math.min(res, node.val - pre.val);
        }
        pre = node;
        dfs(node.right);
    }
}
    
    