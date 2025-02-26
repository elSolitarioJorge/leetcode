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
    
    