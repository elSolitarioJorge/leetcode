const char* R[4][10] = {
    {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
    {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
    {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
    {"", "M", "MM", "MMM"}
};

char* intToRoman(int num) {
    char* ans = (char*)malloc(sizeof(char) * 16);
    strcpy(ans, R[3][num / 1000]);
    strcat(ans, R[2][num % 1000 / 100]);
    strcat(ans, R[1][num % 100 / 10]);
    strcat(ans, R[0][num % 10]);
    return ans;
}
    
    