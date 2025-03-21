#define MAX(a, b) (a > b) ? (a) : (b)

int lowerBound(int* nums, int numsSize, int target){
    int left = -1, right = numsSize;
    while(left + 1 != right){
        int middle = left + (right- left) / 2;
        if(nums[middle] < target){
            left = middle;
        } else{
            right = middle;
        }
    }
    return right;
}

int maximumCount(int* nums, int numsSize) {
    int pos = numsSize - lowerBound(nums, numsSize, 1);
    int neg = lowerBound(nums, numsSize, 0);
    return MAX(pos, neg);
}
    
    