class Solution {
    public String makeFancyString(String s) {
        StringBuilder ans = new StringBuilder();
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            cnt++;
            if (cnt < 3) {
                ans.append(s.charAt(i));
            }
            if (i < s.length() - 1 && s.charAt(i) != s.charAt(i + 1)) {
                cnt = 0;
            }
        }
        return ans.toString();
    }
}
    
    