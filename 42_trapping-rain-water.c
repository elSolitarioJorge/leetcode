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
    
    