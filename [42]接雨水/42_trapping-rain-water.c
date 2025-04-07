// 前缀和分解
int trap(int* height, int heightSize) {
    if(heightSize < 3) return 0;    // 处理边界情况
    int* prevMax = (int*)malloc(sizeof(int) * heightSize);   // preMmax[i] 表示从 height[0] 到 height[i] 的最大值
    int* endMax = (int*)malloc(sizeof(int) * heightSize);   // endMax[i] 表示从 height[i] 到 height[heightSize - 1] 的最大值
    prevMax[0] = height[0];
    endMax[heightSize - 1] = height[heightSize - 1];
    for(int i = 1; i < heightSize; i++){
        prevMax[i] = prevMax[i - 1] > height[i] ? prevMax[i - 1] : height[i];
    }
    for(int i = heightSize - 2; i >= 0; i--){
        endMax[i] = endMax[i + 1] > height[i] ? endMax[i + 1] : height[i];
    }
    int ans = 0;
    for(int i = 0; i < heightSize - 1; i++){
        int min = prevMax[i] < endMax[i] ? prevMax[i] : endMax[i];
        ans += min - height[i];
    }
    free(prevMax);
    free(endMax);
    return ans;
}
// 双指针
int trap(int* height, int heightSize) {
    if(heightSize < 3) return 0;    // 处理边界情况
    int ans = 0, left = 0, right = heightSize - 1;
    int preMax = 0, sufMax = 0;
    while(left <= right){
        preMax = preMax > height[left] ? preMax : height[left];
        sufMax = sufMax > height[right] ? sufMax : height[right];
        if(preMax < sufMax){
            ans += preMax - height[left];
            left++;
        } else{
            ans += sufMax - height[right];
            right--;
        }
    }
    return ans;
}
// 单调栈
int trap(int* height, int heightSize) {
    int ans = 0;
    int stack[20000];
    int top = -1;
    for(int i = 0; i < heightSize; i++) {
        int h_right = height[i];
        while(top >= 0 && h_right >= height[stack[top]]) {
            int h = height[stack[top--]];
            if(top < 0) {
                break;
            }
            int left = stack[top];
            int min = height[left] < h_right ? height[left] : h_right;
            ans += (min - h) * (i - left - 1);
        }
        stack[++top] = i;
    }
    return ans;
}