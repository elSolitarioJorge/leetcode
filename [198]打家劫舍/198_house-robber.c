#define MAX(a, b) a > b ? a : b

int rob(int* nums, int numsSize) {
    int dp[2] = {0};
    for (int i = 0; i < numsSize; i++) {
        int max = MAX(dp[1], dp[0] + nums[i]);
        dp[0] = dp[1];
        dp[1] = max;
    }
    return dp[1];
}
    
    