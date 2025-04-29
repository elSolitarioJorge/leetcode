class Solution {
    public int lastStoneWeightII(int[] stones) {
        int sum = 0;
        for (int weight : stones) {
            sum += weight;
        }
        int target = sum / 2;
        boolean[] dp = new boolean[target + 1];
        dp[0] =  true;
        for (int weight : stones) {
            for (int j = target; j >= weight; j--) {
                if (dp[j - weight]) {
                    dp[j] = true;
                }
            }
        }
        for (int i = target; i >= 0; i--) {
            if (dp[i]) {
                return sum - 2 * i;
            }
        }
        return 0;
    }
}