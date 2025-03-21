#define MAX(a, b) (a > b) ? (a) : (b)

int subarraySum(int* nums, int numsSize) {
    int prevSum[numsSize + 1];
    prevSum[0] = 0;
    for(int i = 0; i < numsSize; i++){
        prevSum[i + 1] = prevSum[i] + nums[i];
    }
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        ans += prevSum[i + 1] - prevSum[MAX(0, i - nums[i])];
    }
    return ans;
}
    
    