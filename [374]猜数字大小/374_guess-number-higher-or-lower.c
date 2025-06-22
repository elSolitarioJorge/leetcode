int guessNumber(int n){
    int left = 1, right = n, middle;
    while (left <= right) {
        middle = left + (right - left) / 2;
        if (guess(middle) == -1) {
            right = middle - 1;
        } else if (guess(middle) == 1) {
            left = middle + 1;
        } else {
            return middle;
        }
    }
    return 0;
}
    
    