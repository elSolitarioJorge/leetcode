class Solution {
    private int res = 0;

    public int minCameraCover(TreeNode root) {
        if (dfs(root) == 0) {
            res++;
        }
        return res;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 2;
        }
        int left = dfs(root.left);
        int right = dfs(root.right);
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        if (left == 1 || right == 1) {
            return 2;
        }
        if (left == 2 && right == 2) {
            return 0;
        }
        return -1;
    }
}
    
    