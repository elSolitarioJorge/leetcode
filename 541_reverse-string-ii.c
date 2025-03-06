char* reverseStr(char* s, int k) {
    int len = strlen(s);
    for(int i = 0; i < len; i += k * 2){
        k = i + k < len ? k : len - i;
        int left = i;
        int right = i + k - 1;
        while(left < right){
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
    return s;
}
    
    