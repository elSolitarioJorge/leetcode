int check(int* time, int timeSize, long long m, int totalTrips){
    long long sum = 0;
    for(int i = 0; i < timeSize; i++){
        sum += m / time[i];
        if(sum >= totalTrips){
            return 1;
        }
    }
    return 0;
}

long long minimumTime(int* time, int timeSize, int totalTrips) {
    long long left = 0, right = LLONG_MAX;
    while(left + 1 != right){
        long long middle = left + (right - left) / 2;
        if(check(time, timeSize, middle, totalTrips)){
            right = middle;
        } else{
            left = middle;
        }
    }
    return right;
}
    
    