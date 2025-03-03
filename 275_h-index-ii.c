int check(int* citations, int citationsSize, int m){
    int count = 0;
    for(int i = 0; i < citationsSize; i++){
        if(citations[i] >= m){
            count++;
        }
        if(count >= m){
            return 1;
        }
    }
    return 0;
}

int hIndex(int* citations, int citationsSize) {
    int left = -1, right = citationsSize + 1;
    while(left + 1 < right){
        int middle = left + (right - left) / 2;
        if(check(citations, citationsSize, middle)){
            left = middle;
        } else{
            right = middle;
        }
    }
    return left;
}
    
    