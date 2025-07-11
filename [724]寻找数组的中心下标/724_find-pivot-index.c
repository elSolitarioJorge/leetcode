int pivotIndex(int *nums, int numsSize)
{
    int i, totalNums = 0, leftNums = 0;
    for (i = 0; i < numsSize; i++)
        totalNums += nums[i] ;
    for (i = 0; i < numsSize; i++)
    {
        if (leftNums * 2 + nums[i] == totalNums)
            return i;
        leftNums += nums[i];
    }
    return -1;
}
    
    