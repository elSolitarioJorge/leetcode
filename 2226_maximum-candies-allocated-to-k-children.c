int check(int* candies, int candiesSize, long long k, int m){
    long long sum = 0;
    for(int i = 0; i < candiesSize; i++){
        sum += candies[i] / m;
        if(sum >= k){
            return 1;
        }
    }
    return 0;
}

int maximumCandies(int* candies, int candiesSize, long long k) {
    int left = 0, right = 10000001;
    while(left + 1 < right){
        int middle = left + (right - left) / 2;
        if(check(candies, candiesSize, k, middle)){
            left = middle;
        } else{
            right = middle;
        }
    }
    return left;
}
    
    