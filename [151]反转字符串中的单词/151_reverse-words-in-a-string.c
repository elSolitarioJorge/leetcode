void reverse(char* s, int l, int r){
    while(l<r){
        char temp = s[l];
        s[l++] = s[r];
        s[r--] = temp;
    }
}
void removeExtraSpace(char* s){
    int beg = 0, end = strlen(s) - 1;
    while(s[beg] == ' '){
        beg++;
    }
    while(s[end]==' '){
        end--;
    }
    int slow = 0;
    for(int fast = beg;fast<=end;fast++){
        if(s[fast]!=' '||s[fast+1]!=' '){
            s[slow++]=s[fast];
        }
    }
    s[slow]='\0';
}
char* reverseWords(char* s) {
    removeExtraSpace(s);
    reverse(s,0,strlen(s)-1);
    int slow = 0;
    for(int fast=0;fast<=strlen(s);fast++){
        if(s[fast]==' '||s[fast]=='\0'){
            reverse(s,slow,fast-1);
            slow=fast+1;
        }
    }
    return s;
}

    
    