int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    int** ans = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n;  i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    int startX = 0, startY = 0;
    int count = 1, offset = 1;
    int mid = n / 2;
    int loop = n / 2;
    while (loop) {
        int i = startX, j = startY;
        while (j < n - offset) {
            ans[startX][j++] = count++;
        }
        while (i < n - offset) {
            ans[i++][j] = count++;
        }
        while (j > startY) {
            ans[i][j--] = count++;
        }
        while (i > startX) {
            ans[i--][j] = count++;
        }
        offset++;
        startX++;
        startY++;
        loop--;
    }
    if (n % 2) {
        ans[mid][mid] = count;
    }
    return ans;
}
    
    