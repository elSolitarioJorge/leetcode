#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

int maxSubArray(int* nums, int numsSize) {
    int ans = INT_MIN;
    int preSum = 0;
    int preMinSum = 0;
    for (int i = 0; i < numsSize; i++) {
        preSum += nums[i];
        ans = MAX(ans, preSum - preMinSum);
        preMinSum = MIN(preMinSum, preSum);
    }
    return ans;
}

#define MAX(a, b) (a > b ? a : b)

int maxSubArray(int* nums, int numsSize) {
    int currentMax = nums[0];
    int globalMax = nums[0];
    for (int i = 1; i < numsSize; i++) {
        currentMax = MAX(nums[i], currentMax + nums[i]);
        globalMax = MAX(globalMax, currentMax);
    }
    return globalMax;
}

#define MAX(a, b) (a > b ? a : b)

int maxSubArray(int* nums, int numsSize) {
    int dp[numsSize];
    dp[0] = nums[0];
    int ans = dp[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = MAX(dp[i - 1], 0) + nums[i];
        ans = MAX(ans, dp[i]);
    }
    return ans;
}

#define MAX(a, b) (a > b ? a : b)

int maxSubArray(int* nums, int numsSize) {
    int ans = INT_MIN;
    int f = 0;
    for (int i = 0; i < numsSize; i++) {
        f = MAX(f, 0) + nums[i];
        ans = MAX(ans, f);
    }
    return ans;
}
    
    