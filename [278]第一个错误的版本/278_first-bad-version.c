int firstBadVersion(int n) {
    int l = 0, r = n, mid;
    while(l + 1 != r){
        mid = l + (r - l) / 2;
        if(isBadVersion(mid)){
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}
    
    