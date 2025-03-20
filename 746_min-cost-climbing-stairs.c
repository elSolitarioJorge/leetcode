int min(int a, int b){
    return a < b ? a : b;
}
int minCostClimbingStairs(int* cost, int costSize) {
    int dp[costSize + 1];
    dp[0] = 0, dp[1] = 0;
    for(int i = 2; i <= costSize; i++){
        dp[i] = min(dp[i - 1] + cost[i - 1] , dp[i - 2] + cost[i - 2]);
    }
    return dp[costSize];
}
    
    