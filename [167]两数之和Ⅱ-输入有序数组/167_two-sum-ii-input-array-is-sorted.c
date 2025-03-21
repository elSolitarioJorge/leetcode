int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int left = 0, right = numbersSize - 1;
    while(1){
        if(numbers[left] + numbers[right] == target){
            ans[0] = left + 1;
            ans[1] = right + 1;
            return ans;
        }
        if(numbers[left] + numbers[right] > target){
            right--;
        } else{
            left++;
        }
    }
}
    
    