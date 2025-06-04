class Solution {
    private final List<List<Integer>> res = new ArrayList<>();
    private final List<Integer> path = new ArrayList<>();
    private int k;

    public List<List<Integer>> combinationSum3(int k, int n) {
        this.k = k;
        dfs(9, n);
        return res;
    }

    private void dfs(int i, int t) {
        int d = k - path.size();
        if (t < 0 || t > (i * 2 - d + 1) * d / 2) {
            return;
        }
        if (d == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int j = i; j >= d; j--) {
            path.add(j);
            dfs(j - 1, t - j);
            path.removeLast();
        }
    }
}

class Solution {
    private final List<List<Integer>> res = new ArrayList<>();
    private final List<Integer> path = new ArrayList<>();
    private int k;

    public List<List<Integer>> combinationSum3(int k, int n) {
        this.k = k;
        dfs(9, n);
        return res;
    }

    private void dfs(int i, int t) {
        int d = k - path.size();
        if (t < 0 || t > (i * 2 - d + 1) * d / 2) {
            return;
        }
        if (d == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        if (i > d) {
            dfs(i - 1, t);
        }
        path.add(i);
        dfs(i - 1, t - i);
        path.removeLast();
    }
}
    
    