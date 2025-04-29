int lastStoneWeightII(int* stones, int stonesSize) {
    int sum = 0;
    for (int i = 0; i < stonesSize; i++) {
        sum += stones[i];
    }
    int target = sum / 2;
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < stonesSize; i++) {
        for (int j = target; j >= stones[i]; j--) {
            if (dp[j - stones[i]]) {
                dp[j] = 1;
            }
        }
    }
    for (int i = target; i >= 0; i--) {
        if (dp[i]) {
            return sum - 2 * i;
        }
    }
    return 0;
}
    
    