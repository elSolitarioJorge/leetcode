void getNext(int* next, const char* s){
    int j = 0;
    next[0] = 0;
    for(int i = 1; i < strlen(s); i++){
        while(j && s[i] != s[j]){
            j = next[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        next[i] = j;
    }
}
int strStr(char* haystack, char* needle) {
    int n = strlen(haystack), m = strlen(needle);
    int next[m];
    getNext(next, needle);
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j && haystack[i] != needle[j]){
            j = next[j - 1];
        }
        if(haystack[i] == needle[j]){
            j++;
        }
        if(j == m){
            return i - j + 1;
        }
    }
    return -1;
}
    
    