class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = postorder.length;
        if (n == 0) {
            return null;
        }
        int leftSize = indexOf(inorder, postorder[n - 1]);
        int[] in1 = Arrays.copyOfRange(inorder, 0, leftSize);
        int[] in2 = Arrays.copyOfRange(inorder, leftSize + 1, n);
        int[] post1 = Arrays.copyOfRange(postorder, 0, leftSize);
        int[] post2 = Arrays.copyOfRange(postorder, leftSize, n - 1);
        TreeNode left = buildTree(in1, post1);
        TreeNode right = buildTree(in2, post2);
        return new TreeNode(postorder[n - 1], left, right);
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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = inorder.length;
        Map<Integer, Integer> index = new HashMap<>(n);
        for (int i = 0; i < n; i++) {
            index.put(inorder[i], i);
        }
        return dfs(0, n, postorder, 0, n, index);
    }

    private TreeNode dfs(int inL, int inR, int[] postorder, int postL, int postR, Map<Integer, Integer> index) {
        if (postL == postR) {
            return null;
        }
        int leftSize = index.get(postorder[postR - 1]) - inL;
        TreeNode root = new TreeNode(postorder[postR - 1]);
        root.left = dfs(inL, inL + leftSize, postorder, postL, postL + leftSize, index);
        root.right = dfs(inL + leftSize + 1, inR, postorder, postL + leftSize, postR - 1, index);
        return root;
    }
}