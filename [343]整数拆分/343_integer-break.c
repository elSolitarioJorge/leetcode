#define MAX(a, b) (a) > (b) ? (a) : (b)

int integerBreak(int n) {
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = MAX(dp[i], MAX(dp[i - j] * j, (i - j) * j));
        }
    }
    return dp[n];
}
    
    