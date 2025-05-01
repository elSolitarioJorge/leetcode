int myAtoi(char* s) {
    int i = 0;
    long long ans = 0;
    while(s[i] == ' '){
        i++;
        if(s[i] == '\0'){
            return 0;
        }
    }
    if(s[i] == '-'){
        i++;
        while(s[i] >= '0' && s[i] <= '9'){
            ans = ans * 10 + s[i++] - '0';
            if(-ans < INT_MIN){
                return INT_MIN;
            }
            if(s[i] == '\0'){
                break;
            }
        }
        return -ans;
    }
    else if(s[i] >= '0' && s[i] <= '9' || s[i++] == '+'){
        while(s[i] >= '0' && s[i] <= '9'){
            ans = ans * 10 + s[i++] - '0';
            if(ans > INT_MAX){
                return INT_MAX;
            }
            if(s[i] == '\0'){
                break;
            }
        }
        return ans;
    }
    else{
        return 0;
    }
}
    
    