bool backspaceCompare(char* s, char* t) {
    int slowIndex, fastIndex;
    for (slowIndex = 0, fastIndex = 0; s[fastIndex] != '\0'; fastIndex++){
        if (s[fastIndex] != '#'){
            s[slowIndex++] = s[fastIndex];
        } else {
            slowIndex--;
            if (slowIndex < 0) {
                slowIndex = 0;
            }
            s[slowIndex] = '\0';
        }
    }
    s[slowIndex] = '\0';
    for (slowIndex = 0, fastIndex = 0; t[fastIndex] != '\0'; fastIndex++){
        if (t[fastIndex] != '#'){
            t[slowIndex++] = t[fastIndex];
        } else {
            slowIndex--;
            if (slowIndex < 0) {
                slowIndex = 0;
            }
            t[slowIndex] = '\0';
        }
    }
    t[slowIndex] = '\0';
    if (strcmp(s, t) == 0){
        return true;
    }
    return false;
}
    
    