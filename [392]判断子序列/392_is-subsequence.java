class Solution {
    public boolean isSubsequence(String s, String t) {
        int n = t.length();
        int[][] nxt = new int[n + 1][26];
        Arrays.fill(nxt[n], n);
        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = nxt[i + 1].clone();
            nxt[i][t.charAt(i) - 'a'] = i;
        }
        int i = -1;
        for (char c : s.toCharArray()) {
            i = nxt[i + 1][c - 'a'];
            if (i == n) {
                return false;
            }
        }
        return true;
    }
}
    
    