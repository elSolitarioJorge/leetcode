typedef struct QNode {
    int val;
    struct QNode* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} MyStack;


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->front = NULL;
    obj->rear = NULL;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = x;
    temp->next = NULL;
    if (obj->rear) {
        obj->rear->next = temp;
    } else {
        obj->front = temp;
    }
    obj->rear = temp;
}

int myStackPop(MyStack* obj) {
    int res = obj->rear->val;
    if (obj->front == obj->rear) {
        free(obj->front);
        obj->front = NULL;
        obj->rear = NULL;
    } else {
        Node* pre = obj->front;
        while (pre->next != obj->rear) {
            pre = pre->next;
        }
        free(pre->next);
        pre->next = NULL;
        obj->rear = pre;
    }
    return res;
}

int myStackTop(MyStack* obj) {
    return obj->rear->val;
}

bool myStackEmpty(MyStack* obj) {
    return obj->front == NULL;
}

void myStackFree(MyStack* obj) {
    Node* cur = obj->front;
    while (cur) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(obj);
}
    
    