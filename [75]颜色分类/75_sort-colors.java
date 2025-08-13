class Solution {
    public void sortColors(int[] nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.length; i++) {
            int x = nums[i];
            nums[i] = 2;
            if (x <= 1) {
                nums[b++] = 1;
            }
            if (x == 0) {
                nums[a++] = 0;
            }
        }
    }
}
    
    