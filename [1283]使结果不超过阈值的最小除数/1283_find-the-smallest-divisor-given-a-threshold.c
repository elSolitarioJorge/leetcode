#define MAX(a, b) (a > b) ? (a) : (b)

int check(int* nums, int numsSize, int m, int threshold){
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += (nums[i] + m - 1) / m;
        if(sum > threshold){
            return 0;
        }
    }
    return 1;
}

int smallestDivisor(int* nums, int numsSize, int threshold) {
    int left = 0, right = nums[0];
    for(int i = 1; i < numsSize; i++){
        right = MAX(right, nums[i]);   // right = MAX(nums), sum = numsSize <= threshold
    }

    while(left + 1 != right){
        int middle = left + (right - left) / 2;
        if(check(nums, numsSize, middle, threshold)){
            right = middle;
        } else{
            left = middle;
        }
    }
    return right;
}
    
    