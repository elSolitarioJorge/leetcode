#define MOD 1000000007

int countGoodStrings(int low, int high, int zero, int one) {
    int ans = 0;
    int dp[high + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= high; i++) {
        if (i >= zero) {
            dp[i] = dp[i - zero];
        }
        if (i >= one) {
            dp[i] = (dp[i] + dp[i - one]) % MOD;
        }
        if (i >= low) {
            ans = (ans + dp[i]) % MOD;
        }
    }
    return ans;
}
    
    