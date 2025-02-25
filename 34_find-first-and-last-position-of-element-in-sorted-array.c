int findLeftBorder(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1;
    while(left <= right){
        int middle = left + (right - left) / 2;
        if(nums[middle] < target){
            left = middle + 1;
        } else{
            right = middle - 1;
        }
    }
    return left;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int start = findLeftBorder(nums, numsSize, target);
    if(start == numsSize || nums[start] != target){
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
    int end = findLeftBorder(nums, numsSize, target + 1) - 1;
    ans[0] = start;
    ans[1] = end;
    return ans;
}
    
    