//贪心
int maxProfit(int* prices, int pricesSize) {
    int ans = 0;
    for (int i = 1; i < pricesSize; i++) {
        int profix = prices[i] - prices[i - 1];
        ans += profix > 0 ? profix : 0;
    }
    return ans;
}

//动态规划
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize) {
    int dp[pricesSize][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++) {
        dp[i][0] = MAX(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = MAX(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[pricesSize - 1][0];
}

//空间优化
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize) {
    int dp0 = 0, dp1 = -prices[0];
    for (int i = 1; i < pricesSize; i++) {
        int new0 = MAX(dp0, dp1 + prices[i]);
        dp1 = MAX(dp1, dp0 - prices[i]);
        dp0 = new0;
    }
    return dp0;
}
    