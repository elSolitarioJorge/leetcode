#define Min(a, b) a < b ? a : b
int minSubArrayLen(int target, int* nums, int numsSize) {
    int ans = numsSize + 1;
    int sum = 0;
    int left = 0;
    for(int right = 0; right < numsSize; right++){
        sum += nums[right];
        while(sum >= target){
            ans = Min(ans, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return ans > numsSize ? 0 : ans;
}
    
    