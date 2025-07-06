class Solution {
    public List<Integer> postorder(Node root) {
        List<Integer> res = new ArrayList<>();
        dfs(root, res);
        return res;
    }

    private void dfs(Node root, List<Integer> res) {
        if (root == null) {
            return;
        }
        for (Node node : root.children) {
            dfs(node, res);
        }
        res.add(root.val);
    }
}
    
    