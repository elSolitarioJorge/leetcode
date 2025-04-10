#define MAX(a, b) ((a) > (b)) ? (a) : (b)

int maxWidthRamp(int* nums, int numsSize) {
    int ans = 0;
    int stack[numsSize];
    int top = -1;
    for (int i = 0; i < numsSize; i++) {
        if (top < 0 || nums[i] < nums[stack[top]]) {
            stack[++top] = i;
        }
    }
    for (int i = numsSize - 1; i >= 0; i--) {
        while (top >= 0 && nums[i] >= nums[stack[top]]) {
            int t = i - stack[top--];
            ans = MAX(ans, t);
        }
    }
    return ans;
}
    
    