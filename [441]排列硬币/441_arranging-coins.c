int arrangeCoins(int n) {
    long long l = 1, r = (long long)n + 1, k;
    while(l + 1 != r){
        k = (l + r) / 2;
        if((k + 1) * k / 2 <= n){
            l = k;
        } else {
            r = k;
        }
    }
    return l;
}
    
    