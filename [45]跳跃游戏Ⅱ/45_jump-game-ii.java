class Solution {
    public int jump(int[] nums) {
        int res = 0;
        int curRight = 0;
        int nextRight = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            nextRight = Math.max(nextRight, i + nums[i]);
            if (i == curRight) {
                curRight = nextRight;
                res++;
            }
        }
        return res;
    }
}
    
    