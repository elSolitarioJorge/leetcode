class Solution {
    public String convert(String s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        List<StringBuilder> list = new ArrayList<>();
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < numRows; i++) {
            list.add(new StringBuilder());
        }
        int idex = 0, t = 2 * numRows - 2;
        for (char c : s.toCharArray()) {
            int r = idex % t;
            int val = r < numRows ? r : t - r;
            list.get(val).append(c);
            idex++;
        }
        for (int i = 0; i < numRows; i++) {
            res.append(list.get(i));
        }
        return res.toString();
    }
}
    
    