typedef struct {
    int* sums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* ret = (NumArray*)malloc(sizeof(NumArray));
    ret->sums = (int*)malloc(sizeof(int) * numsSize);
    ret->sums[0] = nums[0];
    for(int i = 1; i < numsSize; i++){
        ret->sums[i] = ret->sums[i - 1] + nums[i];
    }
    return ret;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return left ? obj->sums[right] - obj->sums[left - 1] : obj->sums[right];
}

void numArrayFree(NumArray* obj) {
    free(obj->sums);
}
    
    