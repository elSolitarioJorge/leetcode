#define Max(a, b) a > b ? a : b
int lengthOfLongestSubstring(char* s) {
    int ans = 0;
    int left = 0;
    int hash[128] = {0};
    for(int right = 0; s[right]; right++){
        char c = s[right];
        hash[c]++;
        while(hash[c] > 1){
            hash[s[left]]--;
            left++;
        }
        ans = Max(ans, right - left + 1);
    }
    return ans;
}
    
    