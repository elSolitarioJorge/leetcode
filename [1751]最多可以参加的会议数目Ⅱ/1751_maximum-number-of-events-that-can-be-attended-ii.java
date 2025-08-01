class Solution {
    public int maxValue(int[][] events, int k) {
        if (k == 1) {
            int mx = 0;
            for (int[] e : events) {
                mx = Math.max(mx, e[2]);
            }
            return mx;
        }

        Arrays.sort(events, (a, b) -> a[1] - b[1]);
        int n = events.length;
        int[][] f = new int[n + 1][k + 1];
        for (int i = 0; i < n; i++) {
            int p = search(events, i, events[i][0]);
            for (int j = 1; j <= k; j++) {
                f[i + 1][j] = Math.max(f[i][j], f[p + 1][j - 1] + events[i][2]);
            }
        }
        return f[n][k];
    }

    private int search(int[][] events, int right, int upper) {
        int left = -1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (events[mid][1] < upper) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
    
    