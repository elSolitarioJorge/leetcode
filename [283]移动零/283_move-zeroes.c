void moveZeroes(int* nums, int numsSize) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < numsSize; fastIndex++){
        if (nums[fastIndex] != 0){
            nums[slowIndex++] = nums[fastIndex];
        }
    }
    while (slowIndex < numsSize) {
        nums[slowIndex++] = 0;
    }
}
    
    