bool isPerfectSquare(int num) {
    int left = 1, right = num, middle;
    while (left <= right) {
        middle = left + (right - left) / 2;
        if (middle > num / middle) {
            right = middle - 1;
        } else if (middle * middle < num) {
            left = middle + 1;
        } else {
            return true;
        }
    }
    return false;
}
    
    