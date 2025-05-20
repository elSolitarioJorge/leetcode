class Solution {
    private final List<List<Integer>> res = new ArrayList<>();
    private final List<Integer> path = new ArrayList<>();
    private int[] nums;

    public List<List<Integer>> subsets(int[] nums) {
        this.nums = nums;
        dfs(0);
        return res;
    }

    private void dfs(int i) {
        res.add(new ArrayList<>(path));

        for (int j = i; j < nums.length; j++) {
            path.add(nums[j]);
            dfs(j + 1);
            path.removeLast();
        }
    }
}

class Solution {
    private final List<List<Integer>> res = new ArrayList<>();
    private final List<Integer> path = new ArrayList<>();
    private int[] nums;

    public List<List<Integer>> subsets(int[] nums) {
        this.nums = nums;
        dfs(0);
        return res;
    }

    private void dfs(int i) {
        if (i == nums.length) {
            res.add(new ArrayList<>(path));
            return;
        }

        dfs(i + 1);

        path.add(nums[i]);
        dfs(i + 1);
        path.removeLast();
    }
}