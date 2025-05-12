class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        TreeNode node = root;
        while (node != null) {
            if (val == node.val) {
                return node;
            } else if (val < node.val) {
                node = node.left;
            } else {
                node = node.right;
            }
        }
        return null;
    }
}
    
    