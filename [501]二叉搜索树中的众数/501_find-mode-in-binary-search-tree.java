class Solution {
    private List<Integer> resList = new ArrayList<>();
    private int count, maxCount;
    private TreeNode pre;

    public int[] findMode(TreeNode root) {
        dfs(root);
        int[] res = new int[resList.size()];
        for (int i = 0; i < resList.size(); i++) {
            res[i] = resList.get(i);
        }
        return res;
    }

    private void dfs(TreeNode node) {
        if (node == null) {
            return;
        }
        dfs(node.left);
        int val = node.val;
        if (pre == null || pre.val != val) {
            count = 1;
        } else {
            count++;
        }
        if (count > maxCount) {
            resList.clear();
            resList.add(val);
            maxCount = count;
        } else if (count == maxCount) {
            resList.add(val);
        }
        pre = node;
        dfs(node.right);
    }
}