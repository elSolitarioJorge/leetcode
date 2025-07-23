bool uniqueOccurrences(int* arr, int arrSize) {
    int count[2001] = {0};
    bool hash[1001] = {false};
    for(int i = 0; i < arrSize; i++){
        count[arr[i] + 1000]++;
    }
    for(int i = 0; i < 2001; i++){
        if(count[i]){
            if(hash[count[i]] == false){
                hash[count[i]] = true;
            }
            else{
                return false;
            }
        }
    }
    return true;
}
    
    