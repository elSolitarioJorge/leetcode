class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int minDepth = 0;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int n = queue.size();
            minDepth++;
            for (int i = 0; i < n; i++) {
                TreeNode node = queue.poll();
                if (node.left == null && node.right == null) {
                    return minDepth;
                }
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
        }
        return minDepth;
    }
}

class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right != null) {
            return minDepth(root.right) + 1;
        }
        if (root.left != null && root.right == null) {
            return minDepth(root.left) + 1;
        }
        return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
    }
}


    
    