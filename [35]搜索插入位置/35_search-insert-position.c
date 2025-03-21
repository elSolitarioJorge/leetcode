int searchInsert(int* nums, int numsSize, int target) {
    int left = -1, right = numsSize;
    while(left + 1 != right){
        int middle = left + (right - left) / 2;
        if(nums[middle] < target){
            left = middle;
        } else{
            right = middle;
        }
    }
    return right;
}
    
    