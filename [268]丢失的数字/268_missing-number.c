// 排序 + 二分
int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}
int missingNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int l = -1, r = numsSize, mid;
    while(l + 1 != r){
        mid = (l + r) / 2;
        if(nums[mid] > mid){
            r = mid;
        }else{
            l = mid;
        }
    }
    return r;
}
// 哈希
int missingNumber(int* nums, int numsSize) {
    int a[10000] = {0};
    for(int i = 0; i < numsSize; i++){
        a[nums[i]]++;
    }
    int k = 0;
    while(a[k] != 0){
        k++;
    }
    return k;
}
// 求和返回差值
int missingNumber(int* nums, int numsSize) {
    int sum = 0, n = numsSize;
    for(int i = 0; i < n; i++){
        sum += nums[i];
    }
    return n * (n + 1) / 2 - sum;
}
// 异或
int missingNumber(int* nums, int numsSize) {
    int ans = numsSize;
    for(int i = 0; i < numsSize; i++){
        ans ^= nums[i];
        ans ^= i;
    }
    return ans;
}
    
    