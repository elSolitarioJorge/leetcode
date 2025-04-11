#define MAX(a, b) (a > b) ? a : b

int largestRectangleArea(int* heights, int heightsSize) {
    int ans = 0;
    int stack[heightsSize + 1];
    int top = -1;
    stack[++top] = -1;
    for (int i = 0; i <= heightsSize; i++) {
        int h = i < heightsSize ? heights[i] : -1;
        while (top > 0 && h <= heights[stack[top]]) {
            int j = stack[top--];
            int s = heights[j] * (i - stack[top] - 1);
            ans = MAX(ans, s);
        }
        stack[++top] = i;
    }
    return ans;
}
    
    