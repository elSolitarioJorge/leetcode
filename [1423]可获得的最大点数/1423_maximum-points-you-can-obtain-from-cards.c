#define MAX(a, b) a > b ? a : b

int maxScore(int* cardPoints, int cardPointsSize, int k) {
    int s = 0;
    for (int i = 0; i < k; i++) {
        s += cardPoints[i];
    }
    int ans = s;
    for (int i = 1; i <= k ; i++) {
        s += cardPoints[cardPointsSize - i] - cardPoints[k - i];
        ans = MAX(ans, s);
    }
    return ans;
}
    
    