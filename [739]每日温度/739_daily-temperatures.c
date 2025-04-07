// 单调栈（从右到左）
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;
    int stack[100000];
    int top = -1;
    for(int i = temperaturesSize - 1; i >= 0; i--) {
        int t = temperatures[i];
        while(top >= 0 && t >= temperatures[stack[top]]) {
            top--;
        }
        ans[i] = top >= 0 ? stack[top] - i : 0;
        stack[++top] = i;
    }
    return ans;
}
// 单调栈（从左到右）
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;
    int stack[100000];
    int top = -1;
    for(int i = i; i < temperaturesSize; i++) {
        int t = temperatures[i];
        while(top >= 0 && t > temperatures[stack[top]]) {
            int j = stack[top--];
            ans[j] = i - j;
        }
        stack[++top] = i;
    }
    // 注意：最后要将栈里元素清空，因为没找到，所以答案均为0，不过这里也可以直接用calloc分配答案数组，将数组元素初始化为0，就可以省去这一步
    while(top >= 0){
        ans[stack[top--]] = 0;
    }
    return ans;
}
    
    