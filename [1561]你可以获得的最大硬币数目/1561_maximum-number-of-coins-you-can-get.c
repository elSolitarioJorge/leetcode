int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maxCoins(int* piles, int n) {
    qsort(piles, n, sizeof(int), cmp);
    int ans = 0;
    for (int i = n / 3; i < n; i += 2) {
        ans += piles[i];
    }
    return ans;
}
    
    