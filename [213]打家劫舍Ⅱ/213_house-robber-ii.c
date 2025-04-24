#define MAX(a, b) (a) > (b) ? (a) : (b)

int rob1(int* nums, int start, int end) {
    int dp[2] = {0};
    for (int i = start; i <= end; i++) {
        int max = MAX(dp[1], dp[0] + nums[i]);
        dp[0] = dp[1];
        dp[1] = max;
    }
    return dp[1];
}

int rob(int* nums, int numsSize) {
    int ans1 = nums[0] + rob1(nums, 2, numsSize - 2);
    int ans2 = rob1(nums, 1, numsSize - 1);
    return MAX(ans1, ans2);
}
    
    