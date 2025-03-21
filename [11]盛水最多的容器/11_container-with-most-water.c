int maxArea(int* height, int heightSize) {
    int ans = 0;
    int left = 0, right = heightSize - 1;
    while(left < right){
        int min = height[left] < height[right] ? height[left] : height[right];
        int area = (right - left) * min;
        ans = ans > area ? ans : area;
        height[left] < height[right] ? left++ : right--;
    }
    return ans;
}
    
    