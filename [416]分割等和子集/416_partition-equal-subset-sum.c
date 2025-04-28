bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum % 2 == 1) {
        return false;
    }
    int target = sum / 2;
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            if(dp[j - nums[i]]) {
                dp[j] = 1;
            }
        }
    }
    return dp[target];
}
    
    