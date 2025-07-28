class Solution {
    public int maxDiff(int num) {
        String s = String.valueOf(num);
        char[] cs = s.toCharArray();

        int mx = num;
        for (char d : cs) {
            if (d != '9') {
                mx = replace(s, d, '9');
                break;
            }
        }

        int mn = num;
        if (cs[0] != '1') {
            mn = replace(s, cs[0], '1');
        } else {
            for (int i = 1; i < cs.length; i++) {
                if (cs[i] > '1') {
                    mn = replace(s, cs[i], '0');
                    break;
                }
            }
        }

        return mx - mn;
    }

    private int replace(String s, char oldChar, char newChar) {
        String t = s.replace(oldChar, newChar);
        return Integer.parseInt(t);
    }
}
    
    