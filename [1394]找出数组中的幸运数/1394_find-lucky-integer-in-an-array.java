class Solution {
    public int findLucky(int[] arr) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : arr) {
            cnt.merge(x, 1, Integer::sum);
        }

        int ans = -1;
        for (Map.Entry<Integer, Integer> e : cnt.entrySet()) {
            int x = e.getKey();
            int c = e.getValue();
            if (x == c) {
                ans = Math.max(ans, x);
            }
        }
        return ans;
    }
}
    
    