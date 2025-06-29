int fib(int n) {
    if (n < 2) {
        return n;
    }
    int dp[2];
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int sum = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = sum;
    }
    return dp[1];
}
    
    