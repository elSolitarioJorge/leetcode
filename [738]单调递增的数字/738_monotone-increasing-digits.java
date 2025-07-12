class Solution {
    public int monotoneIncreasingDigits(int n) {
        String s = String.valueOf(n);
        char[] nums = s.toCharArray();
        int start = nums.length;
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                nums[i] -= 1;
                start = i + 1;
            }
        }
        for (int i = start; i < nums.length; i++) {
            nums[i] = '9';
        }
        return Integer.parseInt(String.valueOf(nums));
    }
}
    
    