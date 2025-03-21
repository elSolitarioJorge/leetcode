char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int left = -1, right = lettersSize;
    while(left + 1 != right){
        int middle = left + (right - left) / 2;
        if(letters[middle] < target + 1){
            left = middle;
        } else{
            right = middle;
        }
    }
    return right == lettersSize ? letters[0] : letters[right];
}
    
    