int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int dp[100][100] = {0};
    for(int i = 0; i < obstacleGridSize && obstacleGrid[i][0] == 0; i++){
        dp[i][0] = 1;
    }
    for(int j = 0; j < *obstacleGridColSize && obstacleGrid[0][j] == 0; j++){
        dp[0][j] = 1;
    }
    for(int i = 1; i < obstacleGridSize; i++){
        for(int j = 1; j < *obstacleGridColSize; j++){
            if(obstacleGrid[i][j] == 1){
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[obstacleGridSize - 1][*obstacleGridColSize - 1];
}
    
    