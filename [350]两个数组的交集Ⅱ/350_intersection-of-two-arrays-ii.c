int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int record[1001] = {0};
    int lessSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* ans = (int*)calloc(lessSize, sizeof(int));
    int size = 0;
    for(int i = 0; i < nums1Size; i++){
        record[nums1[i]]++;
    }
    for(int i = 0; i < nums2Size; i++){
        if(record[nums2[i]]){
            ans[size++] = nums2[i];
            record[nums2[i]] = 0;
        }
    }
    *returnSize = size;
    return ans;
}
    
    