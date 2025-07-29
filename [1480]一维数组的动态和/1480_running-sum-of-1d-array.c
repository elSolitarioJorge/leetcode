int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* profix = (int*)malloc(sizeof(int) * numsSize);
    profix[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        profix[i] = profix[i - 1] + nums[i];
    }
    *returnSize = numsSize;
    return profix;
}
    
    