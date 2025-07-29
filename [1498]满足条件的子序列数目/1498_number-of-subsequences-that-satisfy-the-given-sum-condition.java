class Solution {
    private static final int MOD = 1_000_000_007;
    private static final int[] pow2 = new int[100_000];
    private static boolean initialized = false;
    private void init() {
        if (initialized) {
            return;
        }
        initialized = true;

        pow2[0] = 1;
        for (int i = 1; i < pow2.length; i++) {
            pow2[i] = pow2[i - 1] * 2 % MOD;
        }
    }

    public int numSubseq(int[] nums, int target) {
        init();
        Arrays.sort(nums);
        long ans = 0;
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans += pow2[right - left];
                left++;
            } else {
                right--;
            }
        }
        return (int) (ans % MOD);
    }
}
    
    