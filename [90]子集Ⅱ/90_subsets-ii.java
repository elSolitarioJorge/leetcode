class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();
    private int[] nums;

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        this.nums = nums;
        dfs(0);
        return res;
    }

    private void dfs(int i) {
        if (i == nums.length) {
            res.add(new ArrayList<>(path));
            return;
        }

        path.add(nums[i]);
        dfs(i + 1);
        path.removeLast();

        i++;
        while (i < nums.length && nums[i] == nums[i - 1]) {
            i++;
        }
        dfs(i);
    }
}
    
    