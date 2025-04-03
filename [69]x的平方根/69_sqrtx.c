int mySqrt(int x) {
    int left = 1, right = x, middle;
    while (left <= right) {
        middle = left + (right - left) / 2;
        if (middle > x / middle) {
            right = middle - 1;
        } else if (middle * middle < x) {
            left = middle + 1;
        } else {
            return middle;
        }
    }
    return right;
}
    
    