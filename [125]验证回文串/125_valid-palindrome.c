bool isPalindrome(char* s) {
    int left = 0, right = strlen(s) - 1;
    while(left < right){
        if(!isalnum(s[left])){         // int isalnum(int c)    检查所传字符是不是字母或数字
            left++;
        } else if(!isalnum(s[right])){
            right--;
        } else if(tolower(s[left]) == tolower(s[right])){    // int tolower(int c)    把给定的字母转换为小写字母（如果没有小写，则不变）
            left++;
            right--;
        } else{
            return false;
        }
    }
    return true;
}
    
    