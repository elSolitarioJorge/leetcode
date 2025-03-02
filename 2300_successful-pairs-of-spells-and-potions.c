int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

// 返回 nums 中的第一个大于等于 target 的元素下标
int lowerBound(int* nums, int numsSize, int target){
    int left = -1, right = numsSize;
    while(left + 1 != right){
        int middle = left + (right- left) / 2;
        if(nums[middle] < target){
            left = middle;
        } else{
            right = middle;
        }
    }
    return right;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    int* pairs = (int*)malloc(sizeof(int) * spellsSize);
    *returnSize = spellsSize;
    qsort(potions,  potionsSize, sizeof(int), cmp);
    for(int i = 0; i < spellsSize; i++){
        long long target = (success + spells[i] - 1) / spells[i];   //向上取整
        if(target <= potions[potionsSize - 1]){
            // 这样写每次二分就只用 int 比较，避免把 potions 中的元素转成 long long 比较
            pairs[i] = potionsSize - lowerBound(potions, potionsSize, target);
        } else{
            pairs[i] = 0;
        }
    }
    return pairs;
}
    
    