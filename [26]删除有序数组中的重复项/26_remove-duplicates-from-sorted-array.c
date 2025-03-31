int removeDuplicates(int* nums, int numsSize) {
    int slowIndex = 0;
    for (int fastIndex = 1; fastIndex < numsSize; fastIndex++){
        if (nums[fastIndex] != nums[slowIndex]){
            nums[++slowIndex] = nums[fastIndex];
        }
    }
    return slowIndex + 1;
}
    
    