class Solution {
    public int maxUncrossedLines(int[] s, int[] t) {
        int m = t.length;
        int[] f = new int[m + 1];
        for (int x : s) {
            int pre = 0;
            for (int j = 0; j < m; j++) {
                int tmp = f[j + 1];
                f[j + 1] = x == t[j] ? pre + 1 : Math.max(f[j + 1], f[j]);
                pre = tmp;
            }
        }
        return f[m];
    }
}
    
    