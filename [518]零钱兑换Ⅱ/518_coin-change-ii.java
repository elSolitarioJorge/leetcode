class Solution {
    public int change(int amount, int[] coins) {
        int[] f = new int[amount + 1];
        f[0] = 1;
        for (int x : coins) {
            for (int c = x; c <= amount; c++) {
                f[c] += f[c - x];
            }
        }
        return f[amount];
    }
}
    
    