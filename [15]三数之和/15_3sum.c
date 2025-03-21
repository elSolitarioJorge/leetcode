int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int** ans = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
    *returnSize = 0;
    for(int i = 0; i < numsSize - 2; i++){
        //跳过重复数字
        if(i > 0 && nums[i] == nums[i - 1]){
            continue;
        }
        //优化
        if(nums[i] + nums[i + 1] + nums[i + 2] > 0){
            break;
        }
        if(nums[i] + nums[numsSize - 1] + nums[numsSize - 2] < 0){
            continue;
        }
        int j = i + 1, k = numsSize - 1;
        while(j < k){
            if(nums[i] + nums[j] + nums[k] > 0){
                k--;
            } else if(nums[i] + nums[j] + nums[k] < 0){
                j++;
            } else{
                int* tuple = (int*)malloc(sizeof(int) * 3);
                tuple[0] = nums[i];
                tuple[1] = nums[j];
                tuple[2] = nums[k];
                ans[(*returnSize)] = tuple;
                (*returnColumnSizes)[(*returnSize)++] = 3;
                //跳过重复数字
                do{
                    j++;
                }while(j < k && nums[j] == nums[j - 1]);
                do{
                    k--;
                }while(k > j && nums[k] == nums[k + 1]);
            }
        }
    }
    return ans;
}
    
    