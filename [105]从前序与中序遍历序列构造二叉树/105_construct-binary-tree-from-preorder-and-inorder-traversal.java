class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        if (n == 0) {
            return null;
        }
        int leftSize = indexOf(inorder, preorder[0]);
        int[] in1 = Arrays.copyOfRange(inorder, 0, leftSize);
        int[] in2 = Arrays.copyOfRange(inorder, leftSize + 1, n);
        int[] pre1 = Arrays.copyOfRange(preorder, 1, leftSize + 1);
        int[] pre2 = Arrays.copyOfRange(preorder, leftSize + 1, n);
        TreeNode left = buildTree(pre1, in1);
        TreeNode right = buildTree(pre2, in2);
        return new TreeNode(preorder[0], left, right);
    }

    private int indexOf(int[] a, int x) {
        for (int i = 0; ; i++) {
            if (a[i] == x) {
                return i;
            }
        }
    }
}

class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = inorder.length;
        Map<Integer, Integer> index = new HashMap<>(n);
        for (int i = 0; i < n; i++) {
            index.put(inorder[i], i);
        }
        return dfs(preorder, 0, n, 0, n, index);
    }

    private TreeNode dfs(int[] preorder, int preL, int preR, int inL, int inR, Map<Integer, Integer> index) {
        if (preL == preR) {
            return null;
        }
        int leftSize = index.get(preorder[preL]) - inL;
        TreeNode root = new TreeNode(preorder[preL]);
        root.left = dfs(preorder, preL + 1, preL + leftSize + 1, inL, inL + leftSize, index);
        root.right = dfs(preorder, preL + leftSize + 1, preR, inL + leftSize + 1, inR, index);
        return root;
    }
}