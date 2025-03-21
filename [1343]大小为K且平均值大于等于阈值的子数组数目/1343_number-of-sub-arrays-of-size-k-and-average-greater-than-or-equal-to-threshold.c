int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    int ans = 0, sum = 0;
    for(int i = 0; i < arrSize; i++){
        sum += arr[i];
        if(i < k - 1){
            continue;
        }
        if(sum >= k * threshold){
            ans++;
        }
        sum -= arr[i - k + 1];
    }
    return ans;
}
    
    