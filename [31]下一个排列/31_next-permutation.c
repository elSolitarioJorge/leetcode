void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i >= 0) {
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(&nums[i], &nums[j]);
    }

    int left = i + 1, right = numsSize - 1;
    while (left < right) {
        swap(&nums[left], &nums[right]);
        left++;
        right--;
    }
}
    
    