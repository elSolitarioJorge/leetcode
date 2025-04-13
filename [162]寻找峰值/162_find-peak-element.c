int findPeakElement(int* nums, int numsSize) {
    int left = -1, right = numsSize - 1;
    while (left + 1 != right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] > nums[middle + 1]) {
            right = middle;
        } else {
            left = middle;
        }
    }
    return right;
}
    
    