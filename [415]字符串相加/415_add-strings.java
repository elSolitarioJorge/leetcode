class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder res = new StringBuilder("");
        int len1 = num1.length() - 1;
        int len2 = num2.length() - 1;
        int carry = 0;
        while (len1 >= 0 ||len2 >= 0) {
            int n1 = len1 >= 0 ? num1.charAt(len1--) - '0' : 0;
            int n2 = len2 >= 0 ? num2.charAt(len2--) - '0' : 0;
            int num = n1 + n2 + carry;
            carry = num / 10;
            res.append(num % 10);
        }
        if (carry != 0) {
            res.append(carry);
        }
        return res.reverse().toString();
    }
}
    
    