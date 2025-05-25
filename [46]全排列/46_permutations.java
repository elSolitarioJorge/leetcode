class Solution {
    List<List<Integer>> res = new ArrayList<>();

    public List<List<Integer>> permute(int[] nums) {
        List<Integer> path = Arrays.asList(new Integer[nums.length]);
        boolean[] onPath = new boolean[nums.length];
        dfs(0, nums, path, onPath);
        return res;
    }

    private void dfs(int i, int[] nums, List<Integer> path, boolean[] onPath) {
        if (i == nums.length) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int j = 0; j < nums.length; j++) {
            if (!onPath[j]) {
                path.set(i, nums[j]);
                onPath[j] = true;
                dfs(i + 1, nums, path, onPath);
                onPath[j] = false;
            }
        }
    }
}
    
    