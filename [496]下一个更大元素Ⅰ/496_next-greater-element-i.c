// 暴力解法
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * nums1Size);
    *returnSize = nums1Size;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                int k = 0;
                for (k = j + 1; k < nums2Size; k++) {
                    if (nums2[k] > nums2[j]) {
                        break;
                    }
                }
                ans[i] = k < nums2Size ? nums2[k] : -1;
                break;
            }
        }
    }
    return ans;
}
// 单调栈 + 哈希
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * nums1Size);
    memset(ans, -1, nums1Size * sizeof(int));
    *returnSize = nums1Size;
    int map[10000];
    for (int i = 0; i < 10000; i++) {
        map[i] = -1;
    }
    for (int i = 0; i < nums1Size; i++) {
        map[nums1[i]] = i;
    }
    int stack[nums2Size];
    int top = -1;
    for (int i = 0; i < nums2Size; i++) {
        int cur = nums2[i];
        while (top >= 0 && cur > stack[top]) {
            int index = map[stack[top--]];
            if (index != -1) {
                ans[index] = cur;
            }
        }
        stack[++top] = cur;
    }
    return ans;
}
    
    