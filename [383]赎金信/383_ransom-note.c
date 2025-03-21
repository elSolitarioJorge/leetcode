bool canConstruct(char* ransomNote, char* magazine) {
    int map[26] = {0};
    for(int i = 0; ransomNote[i]; i++){
        map[ransomNote[i] - 'a']--;
    }
    for(int i = 0; magazine[i]; i++){
        map[magazine[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(map[i] < 0){
            return false;
        }
    }
    return true;
}
    
    