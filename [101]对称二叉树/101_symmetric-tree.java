class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isSameTree(root.left, root.right);
    }

    private boolean isSameTree(TreeNode left, TreeNode right) {
        if (left == null || right == null) {
            return left == right;
        }
        return left.val == right.val && isSameTree(left.left, right.right) && isSameTree(left.right, right.left);
    }
}

