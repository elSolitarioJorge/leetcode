typedef struct node{
    int val;
    struct node* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->next = NULL;
    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList* cur = obj;
    for(int i = 0; i <= index; i++){
        cur = cur->next;
        if(cur == NULL){
            return -1;
        }
    }
    return cur->val;
}
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* new = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    new->val = val;
    new->next = obj->next;
    obj->next = new;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* new = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    new->val = val;
    MyLinkedList* tail = obj;
    while(tail->next){
        tail = tail->next;
    }
    new->next = NULL;
    tail->next = new;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* cur = obj;
    for(int i = 0; i < index; i++){
        cur = cur->next;
        if(cur == NULL){
            return;
        }
    }
    MyLinkedList* new = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    new->val = val;
    new->next = cur->next;
    cur->next = new;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* cur = obj;
    for(int i = 0; i < index; i++){
        cur = cur->next;
        if(cur == NULL){
            return;
        }
    }
    if(cur->next == NULL){
        return;
    }
    MyLinkedList* del = cur->next;
    cur->next = del->next;
    free(del);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* cur = obj;
    while(cur){
        MyLinkedList* temp = cur->next;
        free(cur);
        cur = temp;
    }
}

    
    