#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

int maxProfit(int* prices, int pricesSize) {
    int ans = 0;
    int low = INT_MAX;
    for (int i = 0; i < pricesSize; i++) {
        low = MIN(low, prices[i]);
        ans = MAX(ans, prices[i] - low);
    }
    return ans;
}
    
    