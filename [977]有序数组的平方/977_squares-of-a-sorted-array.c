int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* squareNums = (int*)malloc(sizeof(int) * numsSize);
    int beforeIndex = 0, afterIndex = numsSize - 1, pos = numsSize;
    while(--pos >= 0) {
        if (nums[beforeIndex] * nums[beforeIndex] > nums[afterIndex] * nums[afterIndex]){
            squareNums[pos] = nums[beforeIndex] * nums[beforeIndex];
            beforeIndex++;
        } else {
            squareNums[pos] = nums[afterIndex] * nums[afterIndex];
            afterIndex--;
        }
    }
    *returnSize = numsSize;
    return squareNums;
}
    
    