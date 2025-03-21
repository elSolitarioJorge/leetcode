#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxVowels(char* s, int k) {
    int ans = 0, vowel = 0;
    for(int i = 0; s[i]; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            vowel++;
        }
        if(i < k - 1){
            continue;
        }
        ans = MAX(ans, vowel);
        char out = s[i - k + 1];
        if(out == 'a' || out == 'e' || out == 'i' || out == 'o' || out == 'u'){
            vowel--;
        }
    }
    return ans;
}
    
    