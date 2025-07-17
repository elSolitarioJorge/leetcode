class Solution {
    public int totalFruit(int[] fruits) {
        int ans = 0;
        int left = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int right = 0; right < fruits.length; right++) {
            cnt.merge(fruits[right], 1, Integer::sum);
            while (cnt.size() > 2) {
                int out = fruits[left];
                cnt.merge(out, -1, Integer::sum);
                if (cnt.get(out) == 0) {
                    cnt.remove(out);
                }
                left++;
            }
            ans = Math.max(ans, right - left + 1);
        }
        return ans;
    }
}
    
    