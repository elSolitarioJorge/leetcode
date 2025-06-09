class Solution {
    public int minDistance(String text1, String text2) {
        char[] t = text2.toCharArray();
        int m = t.length;
        int[] f = new int[m + 1];
        for (int j = 0; j < m; j++) {
            f[j + 1] = j + 1;
        }
        for (char x : text1.toCharArray()) {
            int pre = f[0];
            f[0]++;
            for (int j = 0; j < m; j++) {
                int tmp = f[j + 1];
                f[j + 1] = x == t[j] ? pre : Math.min(Math.min(f[j + 1], f[j]), pre) + 1;
                pre = tmp;
            }
        }
        return f[m];
    }
}
    
    