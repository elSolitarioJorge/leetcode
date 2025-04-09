//暴力解法
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int* ans = (int*)malloc(pricesSize * sizeof(int));
    *returnSize = pricesSize;
    for (int i = 0; i < pricesSize; i++) {
        int flag = 0;
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[j] <= prices[i]) {
                flag = j;
                break;
            }
        }
        ans[i] = flag ? prices[i] - prices[flag] : prices[i];
    }
    return ans;
}
//单调栈
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int* ans = (int*)malloc(pricesSize * sizeof(int));
    *returnSize = pricesSize;
    int stack[pricesSize];
    int top = -1;
    for (int i = 0; i < pricesSize; i++) {
        int cur = prices[i];
        while (top >= 0 && cur <= prices[stack[top]]) {
            int j = stack[top--];
            ans[j] = prices[j] - cur;
        }
        stack[++top] = i;
    }
    while (top >= 0) {
        int i = stack[top--];
        ans[i] = prices[i];
    }
    return ans;
}
    
    