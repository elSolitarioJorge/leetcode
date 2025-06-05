bool isPalindrome(struct ListNode* head) {
    struct ListNode* cur = head;
    int len = 0;
    while(cur){
        len++;
        cur = cur->next;
    }
    int arr[len];
    cur = head;
    for(int i = 0; i < len; i++){
        arr[i] = cur->val;
        cur = cur->next;
    }
    int l = 0, r = len - 1;
    while(l < r){
        if(arr[l++] != arr[r--]){
            return false;
        }
    }
    return true;
}
    
    