int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int ans = 0;
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    for (int i = 0; i < sSize; i++) {
        if (ans < gSize && s[i] >= g[ans]) {
            ans++;
        }
    }
    return ans;
}
    
    