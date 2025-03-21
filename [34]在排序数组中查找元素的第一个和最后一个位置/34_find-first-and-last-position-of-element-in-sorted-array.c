int lowerBound1(int* nums, int len, int target){
    int left = 0, right = len - 1;    // 闭区间[left, right]
    while(left <= right){   //区间不为空
        int middle = left + (right - left) / 2;
        if(nums[middle] < target){
            left = middle + 1;    // [middle + 1, right]
        } else{
            right = middle - 1;    // left[left, middle - 1]
        }
    }
    return right + 1;
}

int lowerBound2(int* nums, int numsSize, int target){
    int left = 0, right = numsSize;    //左闭右开[left, right)
    while(left < right){ // 区间不为空
        int middle = left + (right - left) / 2;
        if(nums[middle] < target){
            left = middle + 1;    // [middle + 1, right)
        } else{
            right = middle;    // [left, middle)
        }
    }
    return right;
}

int lowerBound3(int* nums, int numsSize, int target){
    int left = -1, right = numsSize;    //开区间(left, right)
    while(left + 1 != right){ // 区间不为空
        int middle = left + (right - left) / 2;
        if(nums[middle] < target){
            left = middle;    // (middle, right)
        } else{
            right = middle;    // (left, middle)
        }
    }
    return right;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    ans[0] = -1;
    ans[1] = -1;
    int start = lowerBound1(nums, numsSize, target);
    if(start == numsSize || nums[start] != target){
        return ans;
    }
    ans[0] = start;
    ans[1] = lowerBound1(nums, numsSize, target + 1) - 1;
    return ans;
}
    
    