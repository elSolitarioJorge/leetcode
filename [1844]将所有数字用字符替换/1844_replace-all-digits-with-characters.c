void shift(char* a,char* b){
    *b = *a + *b - '0';
}
char* replaceDigits(char* s) {
    int len = strlen(s);
    for(int i = 1;i < len;i += 2){
        shift(&s[i - 1], &s[i]);
    }
    return s;
}
    
    