int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * codeSize);
    *returnSize = codeSize;
    int right = k > 0 ? k + 1 : codeSize;
    k = abs(k);
    int sum = 0;
    for (int i = right - k; i < right; i++) {
        sum += code[i];
    }
    for (int i = 0; i < codeSize; i++) {
        ans[i] = sum;
        sum += code[right % codeSize] - code[(right - k) % codeSize];
        right++;
    }
    return ans;
}
    
    