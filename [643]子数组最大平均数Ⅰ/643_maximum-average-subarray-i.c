#define MAX(a, b) ((a) > (b) ? (a) : (b))
double findMaxAverage(int* nums, int numsSize, int k) {
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
        if(i < k - 1){
            continue;
        }
        maxSum = MAX(maxSum, sum);
        sum -= nums[i - k + 1];
    }
    return (double)maxSum / k;
}
    
    