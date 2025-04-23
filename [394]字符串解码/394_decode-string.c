//递归
char* decode(char* s, int* i) {
    char* res = (char*)calloc(10000, sizeof(char));
    while (s[*i] && s[*i] != ']') {
        if (isdigit(s[*i])) {
            int num = 0;
            while (isdigit(s[*i])) {
                num = num * 10 + (s[*i] - '0');
                (*i)++;
            }
            (*i)++;
            char* sub = decode(s, i);
            (*i)++;
            for (int j = 0; j < num; j++) {
                strcat(res, sub);
            }
            free(sub);
        } else {
            int len = strlen(res);
            res[len] = s[*i];
            res[len + 1] = '\0';
            (*i)++;
        }
    }
    return res;
}
//非递归
char* decodeString(char* s) {
    int i = 0;
    return decode(s, &i);
}

char* decodeString(char* s) {
    char* strStack[100];
    int numStack[100];
    int top = -1;
    char* cur = (char*)calloc(10000, sizeof(char));
    int num = 0;
    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            strStack[++top] = cur;
            numStack[top] = num;
            cur = (char*)calloc(10000, sizeof(char));
            num = 0;
        } else if (s[i] == ']') {
            char* pre = strStack[top];
            int repeat = numStack[top--];
            for (int j = 0; j < repeat; j++) {
                strcat(pre, cur);
            }
            free(cur);
            cur = pre;
        } else {
            int len = strlen(cur);
            cur[len] = s[i];
            cur[len + 1] = '\0';
        }
    }
    return cur;
}


    
    