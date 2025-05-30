class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path =new ArrayList<>();
        dfs(root, targetSum, path, res);
        return res;
    }

    private void dfs(TreeNode node, int targetSum, List<Integer> path, List<List<Integer>> res) {
        if (node == null) {
            return;
        }
        path.add(node.val);
        targetSum -= node.val;
        if (node.left == node.right && targetSum == 0) {
            res.add(new ArrayList<>(path));
        } else {
            dfs(node.left, targetSum, path, res);
            dfs(node.right, targetSum, path, res);
        }
        path.remove(path.size() - 1);
    }
}
    
    