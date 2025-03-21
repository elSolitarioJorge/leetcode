int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }
    int total = matrixSize * (matrixColSize[0]);
    int* ans = (int*)malloc(sizeof(int) * total);
    *returnSize = total;
    int up = 0, down = matrixSize - 1, left = 0, right = matrixColSize[0] - 1;
    int x = 0, y = 0;
    for (int i = 0; i < total; i++) {
        ans[i] = matrix[x][y];
        if(x == up && y != right) {
            y++;
        } else if(y == right && x != down) {
            x++;
        } else if(x == down && y != left) {
            y--;
        } else if(y == left && x != up + 1) {
            x--;
        } else {
            y++;
            up++;down--;left++;right--;
        }
    }
    return ans;
}
    
    