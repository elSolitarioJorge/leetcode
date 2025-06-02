class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int res = 0;
        int minS = 0;
        int sum = 0;
        for (int i = 0; i < gas.length; i++) {
            sum += gas[i] - cost[i];
            if (sum < minS) {
                minS = sum;
                res = i + 1;
            }
        }
        return sum < 0 ? -1 : res;
    }
}
    
    