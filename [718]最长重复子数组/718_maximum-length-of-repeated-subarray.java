class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        int ans = 0;
        int[][] f = new int[n + 1][m + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                    ans = Math.max(ans, f[i + 1][j + 1]);
                }
            }
        }
        return ans;
    }
}
    
    