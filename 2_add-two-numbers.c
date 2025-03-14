typedef struct ListNode Node;
int listLen(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}
void addList(Node* l1, Node* l2){
    Node* cur1 = l1;
    Node* cur2 = l2;
    while(cur2){
        cur1->val += cur2->val;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    cur1 = l1;
    while(cur1){
        if(cur1->val >= 10){
            cur1->val -= 10;
            if(cur1->next == NULL){
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->next = NULL;
                newNode->val = 0;
                cur1->next = newNode;
            }
            cur1->next->val += 1;
        }
        cur1 = cur1->next;
    }
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int len1 = listLen(l1), len2 = listLen(l2);
    if(len1 > len2){
        addList(l1, l2);
        return l1;
    } else {
        addList(l2, l1);
        return l2;
    }
}
    
    