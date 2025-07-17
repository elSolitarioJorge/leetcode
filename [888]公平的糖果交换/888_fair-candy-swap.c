int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
    int sumA = 0, sumB = 0;
    int* ans = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for(int i = 0; i < aliceSizesSize; i++){
        sumA += aliceSizes[i];
    }
    for(int i = 0; i < bobSizesSize; i++){
        sumB += bobSizes[i];
    }
    if(sumA > sumB){
        int gap = (sumA - sumB) / 2;
        for(int i = 0; i < aliceSizesSize; i++){
            for(int j = 0; j < bobSizesSize; j++){
                if(aliceSizes[i] - bobSizes[j] == gap){
                    ans[0] = aliceSizes[i];
                    ans[1] = bobSizes[j];
                    return ans;
                }
            }
        }
    }
    else{
        int gap = (sumB - sumA) / 2;
        for(int i = 0; i < aliceSizesSize; i++){
            for(int j = 0; j < bobSizesSize; j++){
                if(bobSizes[j] - aliceSizes[i] == gap){
                    ans[0] = aliceSizes[i];
                    ans[1] = bobSizes[j];
                    return ans;
                }
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
    
    