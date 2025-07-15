int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int m = matrixSize, n = matrixColSize[0];
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    int** ans = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
        ans[i] = (int*)malloc(sizeof(int) * m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = matrix[j][i];
        }
    }
    return ans;
}
    
    