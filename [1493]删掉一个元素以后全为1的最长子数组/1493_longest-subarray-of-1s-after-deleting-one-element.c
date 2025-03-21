#define MAX(a, b) (a > b) ? (a) : (b)

int longestSubarray(int* nums, int numsSize) {
    int ans = 0;
    int left = 0;
    int count = 0;//记录0的数量
    for(int right = 0; right < numsSize; right++){
        if(nums[right] == 0){
            count++;
        }
        while(count > 1){
            if(nums[left] == 0){
                count--;
            }
            left++;
        }
        ans = MAX(ans, right - left);//必须删除一个元素
    }
    return ans;
}
    
    