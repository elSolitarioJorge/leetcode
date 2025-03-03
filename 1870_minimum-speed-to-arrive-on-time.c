int check(int* dist, int distSize, int m, double hour){
    double sum = 0;
    for(int i = 0; i < distSize - 1; i++){
        sum += (dist[i] + m - 1) / m;
        if(sum > hour){
            return 0;
        }
    }
    sum += (double)dist[distSize - 1] / m;
    return sum <= hour;
}

int minSpeedOnTime(int* dist, int distSize, double hour) {
    int left = 0, right = 10000000;
    while(left + 1 < right){
        int middle = left + (right - left) / 2;
        if(check(dist, distSize, middle, hour)){
            right = middle;
        } else {
            left = middle;
        }
    }
    return check(dist, distSize, right, hour) ? right : -1;
}
    
    