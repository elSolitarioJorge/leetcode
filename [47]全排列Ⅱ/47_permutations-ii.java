class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> path;
    boolean[] onPath;
    int[] nums;

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        this.nums = nums;
        path = Arrays.asList(new Integer[nums.length]);
        onPath = new boolean[nums.length];
        dfs(0);
        return res;
    }

    private void dfs(int i) {
        if (i == nums.length) {
            res.add(new ArrayList<>(path));
            return;
        }

        for (int j = 0; j < nums.length; j++) {
            if (onPath[j] || j > 0 && nums[j] == nums[j - 1] && !onPath[j - 1]) {
                continue;
            }
            path.set(i, nums[j]);
            onPath[j] = true;
            dfs(i + 1);
            onPath[j] = false;
        }
    }
}
    
    