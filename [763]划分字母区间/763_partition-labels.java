class Solution {
    public List<Integer> partitionLabels(String s) {
        char[] chars = s.toCharArray();
        int n = chars.length;
        int[] last = new int[26];
        for (int i = 0; i < n; i++) {
            last[chars[i] - 'a'] = i;
        }
        List<Integer> res = new ArrayList<>();
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            end = Math.max(end, last[chars[i] - 'a']);
            if (end == i) {
                res.add(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
}
    
    