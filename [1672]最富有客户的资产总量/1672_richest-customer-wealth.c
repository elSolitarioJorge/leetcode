int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int max = 0;
    for(int i = 0; i < accountsSize; i++){
        int sum = 0;
        for(int j = 0; j < *accountsColSize; j++){
            sum += accounts[i][j];
        }
        max = (max > sum) ? max : sum;
    }
    return max;
}
    
    