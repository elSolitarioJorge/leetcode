bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    long long a = 0, b = x;
    while (b) {
        a = b % 10 + a * 10;
        b /= 10;
    }
    return a == x;
}
    
    