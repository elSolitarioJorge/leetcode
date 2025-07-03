class Solution {
    public int maxDepth(Node root) {
        if (root == null) {
            return 0;
        }
        int maxChildDepth = 0;
        for (Node child : root.children) {
            maxChildDepth = Math.max(maxChildDepth, maxDepth(child));
        }
        return maxChildDepth + 1;
    }
}
    
    