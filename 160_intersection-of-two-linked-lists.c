struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    typedef struct ListNode Node;
    int lenA = 0, lenB = 0;
    Node* temp = headA;
    while(temp){
        lenA++;
        temp = temp->next;
    }
    temp = headB;
    while(temp){
        lenB++;
        temp = temp->next;
    }
    Node* curA = headA;
    Node* curB = headB;
    if(lenA > lenB){
        int skip = lenA - lenB;
        while(skip--){
            curA = curA->next;
        }
    }
    else{
        int skip = lenB - lenA;
        while(skip--){
            curB = curB->next;
        }
    }
    while(curA != curB){
        curA = curA->next;
        curB = curB->next;
    }
    return curA;
}
    
    