#define MAX(a, b) (a) > (b) ? (a) : (b)

int rob(int* nums, int numsSize) {
    int dp[2] = {0};
    for (int i = 0; i < numsSize; i++) {
        int max = MAX(dp[1], dp[0] + nums[i]);
        dp[0] = dp[1];
        dp[1] = max;
    }
    return dp[1];
}

int deleteAndEarn(int* nums, int numsSize) {
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        max = MAX(max, nums[i]);
    }
    int map[max + 1];
    memset(map, 0, sizeof(map));
    for (int i = 0; i < numsSize; i++) {
        map[nums[i]] += nums[i];
    }
    int res = rob(map, max + 1);
    return res;
}
    
    