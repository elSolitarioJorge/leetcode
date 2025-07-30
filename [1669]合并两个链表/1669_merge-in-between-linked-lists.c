struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode* curA = list1;
    for (int i = 0; i < a - 1; i++) {
        curA = curA->next;
    }
    for (int i = a; i <= b; i++) {
        struct ListNode* del = curA->next;
        curA->next = del->next;
        free(del);
    }
    struct ListNode* end = curA->next;
    struct ListNode* curB = list2;
    curA->next = curB;
    while (curB->next) {
        curB = curB->next;
    }
    curB->next = end;
    return list1;
}
    
    