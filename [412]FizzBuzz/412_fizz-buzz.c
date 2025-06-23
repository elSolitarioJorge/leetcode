char** fizzBuzz(int n, int* returnSize) {
    char** ans = (char**)malloc(sizeof(char*) * n);
    for(int i = 0; i < n; i++){
        ans[i] = (char*)malloc(sizeof(char) * 9);
    }
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0 && i % 5 == 0){
            ans[i - 1] = "FizzBuzz";
        }else if(i % 3 == 0){
            ans[i - 1] = "Fizz";
        }else if(i % 5 == 0){
            ans[i - 1] = "Buzz";
        }else{
            sprintf(ans[i -1], "%d", i);
        }
    }
    *returnSize = n;
    return ans;
}
    
    