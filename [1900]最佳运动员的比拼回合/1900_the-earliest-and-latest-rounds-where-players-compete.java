class Solution {
    public int[] earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int[][][][] memo = new int[n + 1][n + 1][n + 1][2];
        return dfs(n, firstPlayer, secondPlayer, memo);
    }

    private int[] dfs(int n, int first, int second, int[][][][] memo) {
        if (first + second == n + 1) {
            return new int[]{1, 1};
        }

        if (first + second > n + 1) {
            int tmp = first;
            first = n + 1 - second;
            second = n + 1 - tmp;
        }

        int[] mem = memo[n][first][second];
        if (mem[0] > 0) {
            return mem;
        }

        int m = (n + 1) / 2;
        int minMid = second <= m ? 0 : second - n / 2 - 1;
        int maxMid = second <= m ? second - first : m - first;
        int earliest = Integer.MAX_VALUE;
        int latest = 0;

        for (int left = 0; left < first; left++) {
            for (int mid = minMid; mid < maxMid; mid++) {
                int[] res = dfs(m, left + 1, left + mid + 2, memo);
                earliest = Math.min(earliest, res[0]);
                latest = Math.max(latest, res[1]);
            }
        }

        mem[0] = earliest + 1;
        mem[1] = latest + 1;
        return mem;
    }
}
    
    