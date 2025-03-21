int* getAverages(int* nums, int numsSize, int k, int* returnSize) {
    int* avgs = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    memset(avgs, -1, sizeof(int) * numsSize);
    long long sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
        if(i < 2 * k){
            continue;
        }
        avgs[i - k] = sum / (2 * k + 1);
        sum -= nums[i - 2 * k];
    }
    return avgs;
}
    
    