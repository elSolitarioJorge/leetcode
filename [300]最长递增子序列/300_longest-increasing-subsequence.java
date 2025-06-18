class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length, ans = 0;
        int[] f = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    f[i] = Math.max(f[i], f[j]);
                }
            }
            ans = Math.max(ans, ++f[i]);
        }
        return ans;
    }
}
    
    