class Solution {
    private int[] nums;
    private int[][] memo;

    public int findTargetSumWays(int[] nums, int target) {
        int s = 0;
        for (int x : nums) {
            s += x;
        }
        s -= Math.abs(target);
        if (s < 0 || s % 2 == 1) {
            return 0;
        }
        int m = s / 2;
        this.nums = nums;
        int n = nums.length;
        memo = new int[n][m + 1];
        for (int[] me : memo) {
            Arrays.fill(me, -1);
        }
        return dfs(n - 1, m);
    }

    private int dfs(int i, int c) {
        if (i < 0) {
            return c == 0 ? 1 : 0;
        }

        if (memo[i][c] != -1) {
            return memo[i][c];
        }
        if (c < nums[i]) {
            return memo[i][c] = dfs(i - 1, c);
        }
        return memo[i][c] = dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
    }
}
    
    