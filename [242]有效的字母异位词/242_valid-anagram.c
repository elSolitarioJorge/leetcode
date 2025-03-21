bool isAnagram(char* s, char* t) {
    if(strlen(s) != strlen(t)){
        return false;
    }
    int map1[26] = {0}, map2[26] = {0};
    for(int i = 0; s[i]; i++){
        map1[s[i] - 'a'] += 1;
        map2[t[i] - 'a'] += 1;
    }
    for(int i = 0; i < 26; i++){
        if(map1[i] != map2[i]){
            return false;
        }
    }
    return true;
}
    
    