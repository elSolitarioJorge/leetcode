class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();
    private int[] candidates;

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
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

        for (int j = i; j < candidates.length && candidates[j] <= t; j++) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }
            path.add(candidates[j]);
            dfs(j + 1, t - candidates[j]);
            path.removeLast();
        }
    }
}

class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();
    private int[] candidates;

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
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

        path.add(candidates[i]);
        dfs(i + 1, t - candidates[i]);
        path.removeLast();

        i++;
        while (i < candidates.length && candidates[i] == candidates[i - 1]) {
            i++;
        }

        dfs(i, t);
    }
}
    
    