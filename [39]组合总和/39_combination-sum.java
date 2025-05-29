class Solution {
    private final List<List<Integer>> res = new ArrayList<>();
    private final List<Integer> path = new ArrayList<>();
    private int[] candidates;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        this.candidates = candidates;
        dfs(0, target);
        return res;
    }

    private void dfs(int i, int t) {
        if (t == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        if (i == candidates.length || t < 0) {
            return;
        }
        dfs(i + 1, t);
        path.add(candidates[i]);
        dfs(i, t - candidates[i]);
        path.removeLast();
    }
}

class Solution {
    private final List<List<Integer>> res = new ArrayList<>();
    private final List<Integer> path = new ArrayList<>();
    private int[] candidates;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return res;
    }

    private void dfs(int i, int t) {
        if (t == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        if (i == candidates.length || t < candidates[i]) {
            return;
        }
        dfs(i + 1, t);
        path.add(candidates[i]);
        dfs(i, t - candidates[i]);
        path.removeLast();
    }
}

class Solution {
    private final List<List<Integer>> res = new ArrayList<>();
    private final List<Integer> path = new ArrayList<>();
    private int[] candidates;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates = candidates;
        dfs(0, target);
        return res;
    }

    private void dfs(int i, int t) {
        if (t == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        if (t < candidates[i]) {
            return;
        }
        for (int j = i; j < candidates.length; j++) {
            path.add(candidates[j]);
            dfs(j, t - candidates[j]);
            path.removeLast();
        }
    }
}
    
    