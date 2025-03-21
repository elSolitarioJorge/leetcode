int romanToInt(char* s) {
    int hash[128];
    hash['I'] = 1;
    hash['V'] = 5;
    hash['X'] = 10;
    hash['L'] = 50;
    hash['C'] = 100;
    hash['D'] = 500;
    hash['M'] = 1000;
    int ans = 0, i = 0;
    for(; s[i + 1]; i++){
        ans += hash[s[i]] < hash[s[i + 1]] ? -hash[s[i]] : hash[s[i]];
    }
    return ans + hash[s[i]];
}
    
    