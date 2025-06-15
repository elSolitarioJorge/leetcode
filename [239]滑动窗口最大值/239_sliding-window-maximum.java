int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = numsSize - k + 1;
    int queue[numsSize];
    int front = 0, rear = 0;
    for (int i = 0; i < numsSize; i++) {
        while (front < rear && nums[queue[rear - 1]] <= nums[i]) {
            rear--;
        }
        queue[rear++] = i;
        if (i - queue[front] + 1 > k) {
            front++;
        }
        if (i >= k - 1) {
            ans[i - k + 1] = nums[queue[front]];
        }
    }
    return ans;
}
    
    