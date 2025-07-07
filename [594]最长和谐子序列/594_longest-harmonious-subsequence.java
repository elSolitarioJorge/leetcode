class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>(nums.length);
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }

        int ans = 0;
        for (Map.Entry<Integer, Integer> e : cnt.entrySet()) {
            int x = e.getKey();
            Integer c2 = cnt.get(x + 1);
            if (c2 != null) {
                ans = Math.max(ans, e.getValue() + c2);
            }
        }
        return ans;
    }
}
    
    