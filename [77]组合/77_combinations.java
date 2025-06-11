class Solution {
    private int k;
    private final List<List<Integer>> res = new ArrayList<>();
    private final List<Integer> path = new ArrayList<>();

    public List<List<Integer>> combine(int n, int k) {
        this.k = k;
        dfs(n);
        return res;
    }

    private void dfs(int i) {
        int d = k - path.size();
        if (d == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        if (i > d) {
            dfs(i - 1);
        }

        path.add(i);
        dfs(i - 1);
        path.removeLast();
    }
}
    
    