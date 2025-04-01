struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = NULL;
    struct ListNode* l1 = list1;
    struct ListNode* l2 = list2;
    struct ListNode* pre = dummyHead;
    while(l1 && l2){
        if(l1->val <= l2->val){
            pre->next = l1;
            l1 = l1->next;
        } else {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    pre->next = l1 == NULL ? l2 : l1;
    struct ListNode* head = dummyHead->next;
    free(dummyHead);
    return head;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* list = NULL;
    for(int i = 0; i < listsSize; i++){
        list = mergeTwoLists(list, lists[i]);
    }
    return list;
}

    
    