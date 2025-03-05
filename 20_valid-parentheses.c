char pairs(char a){
    if(a == ')') return '(';
    if(a == ']') return '[';
    if(a == '}') return '{';
    return 0;
}

bool isValid(char* s) {
    int len = strlen(s);
    if(len % 2 == 1){
        return false;
    }
    int stack[len], top = -1;
    for(int i = 0; s[i]; i++){
        char ch = pairs(s[i]);
        if(ch){
            if(top < 0 || stack[top] != ch){
                return false;
            }
            top--;
        } else{
            stack[++top] = s[i];
        }
    }
    return top < 0;
}
    
    