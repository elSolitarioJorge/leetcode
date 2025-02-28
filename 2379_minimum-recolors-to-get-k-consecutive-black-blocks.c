#define MIN(a, b) ((a) < (b) ? (a) : (b))
int minimumRecolors(char* blocks, int k) {
    int ans = INT_MAX, numW = 0;
    for(int i = 0; blocks[i]; i++){
        if(blocks[i] == 'W'){
            numW++;
        }
        if(i < k - 1){
            continue;
        }
        ans = MIN(ans, numW);
        if(blocks[i - k + 1] == 'W'){
            numW--;
        }
    }
    return ans;
}
    
    