class Solution {
    public String predictPartyVictory(String senate) {
        char[] s = senate.toCharArray();
        boolean r = true, d = true;
        int flag = 0;
        while (r && d) {
            r = false;
            d = false;
            for (int i = 0; i < s.length; i++) {
                if (s[i] == 'R') {
                    if (flag < 0) {
                        s[i] = 0;
                    } else {
                        r = true;
                    }
                    flag++;
                }
                if (s[i] == 'D') {
                    if (flag > 0) {
                        s[i] = 0;
                    } else {
                        d = true;
                    }
                    flag--;
                }
            }
        }
        return r == true ? "Radiant" : "Dire";
    }
}
    
    