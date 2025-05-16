class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        TreeNode node = new TreeNode(val);
        if (root == null) {
            return node;
        }
        TreeNode cur = root;
        TreeNode pre = root;
        while (cur != null) {
            pre = cur;
            if (val < cur.val) {
                cur = cur.left;
            } else {
                cur = cur.right;
            }
        }
        if (val < pre.val) {
            pre.left = node;
        } else {
            pre.right = node;
        }
        return root;
    }
}

class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }
        if (val < root.val) {
            root.left = insertIntoBST(root.left, val);
        } else {
            root.right = insertIntoBST(root.right, val);
        }
        return root;
    }
}