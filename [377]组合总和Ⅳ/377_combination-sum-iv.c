int combinationSum4(int* nums, int numsSize, int target) {
    unsigned dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < numsSize; j++) {
            int num = nums[j];
            if (num <= i) {
                dp[i] += dp[i - num];
            }
        }
    }
    return dp[target];
}
    
    