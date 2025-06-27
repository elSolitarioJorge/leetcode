class Solution {
    private int[] cnt0;
    private int[][][] memo;
    private String[] strs;

    public int findMaxForm(String[] strs, int m, int n) {
        this.strs = strs;
        int k = strs.length;
        cnt0 = new int[k];
        for (int i = 0; i < k; i++) {
            cnt0[i] = (int)strs[i].chars().filter(ch -> ch == '0').count();
        }
        memo = new int[k][m + 1][n + 1];
        for (int[][] mat : memo) {
            for (int[] arr : mat) {
                Arrays.fill(arr, -1);
            }
        }
        return dfs(k - 1, m, n);
    }

    private int dfs(int i, int j, int k) {
        if (i < 0) {
            return 0;
        }
        if (memo[i][j][k] != -1) {
            return memo[i][j][k];
        }
        int res = dfs(i - 1, j, k);
        int cnt1 = strs[i].length() - cnt0[i];
        if (j >= cnt0[i] && k >= cnt1) {
            res = Math.max(res, dfs(i - 1, j - cnt0[i], k - cnt1) + 1);
        }
        return memo[i][j][k] = res;
    }
}
    
    