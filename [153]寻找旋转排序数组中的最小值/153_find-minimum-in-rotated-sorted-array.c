int findMin(int* nums, int numsSize) {
    int left = -1, right = numsSize;
    while (left + 1 != right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] > nums[numsSize - 1]) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return nums[right];
}
    
    