// 单调栈
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    memset(ans, -1, numsSize * sizeof(int));
    *returnSize = numsSize;
    int stack[numsSize];
    int top = -1;
    for (int i = 0; i < 2 * numsSize; i++) {
        int cur = nums[i % numsSize];
        while (top >= 0 && cur > nums[stack[top]]) {
            ans[stack[top--]] = cur;
        }
        if (i < numsSize) {
            stack[++top] = i;
        }
    }
    return ans;
}
    
    