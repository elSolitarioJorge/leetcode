#define MAX(a, b) (a > b) ? (a) : (b)

int equalSubstring(char* s, char* t, int maxCost) {
    int costs[100000] = {0};
    int ans = 0;
    int sumCost = 0;
    int left = 0;
    for(int right = 0; s[right]; right++){
        costs[right] = abs(s[right] - t[right]);
        sumCost += costs[right];
        while(sumCost > maxCost){
            sumCost -= costs[left];
            left++;
        }
        ans = MAX(ans, right - left + 1);
    }
    return ans;
}
    
    