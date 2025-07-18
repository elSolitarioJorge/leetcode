int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    int a[(numsSize + 1) / 2], b[numsSize / 2];
    int m = 0, n = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] % 2 == 0){
            a[m++] = nums[i];
        } else {
            b[n++] = nums[i];
        }
    }
    m = 0, n = 0;
    for(int i = 0; i < numsSize; i++){
        if(i % 2 == 0){
            ans[i] = a[m++];
        } else {
            ans[i] = b[n++];
        }
    }
    return ans;
}
    
    