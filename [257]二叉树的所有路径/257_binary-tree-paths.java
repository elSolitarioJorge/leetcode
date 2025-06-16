class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<>();
        List<String> path = new ArrayList<>();
        dfs(root, path, res);
        return res;
    }

    private void dfs(TreeNode node, List<String> path, List<String> res) {
        if (node == null) {
            return;
        }
        path.add(String.valueOf(node.val));
        if (node.left == node.right) {
            res.add(String.join("->", path));
        } else {
            dfs(node.left, path, res);
            dfs(node.right, path, res);
        }
        path.remove(path.size() - 1);
    }
}
    
    