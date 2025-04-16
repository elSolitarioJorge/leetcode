typedef struct {
    int stkInTop, stkOutTop;
    int stkIn[100], stkOut[100];
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->stkInTop = -1;
    obj->stkOutTop = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stkIn[++(obj->stkInTop)] = x;
}

int myQueuePop(MyQueue* obj) {
    int stkInTop = obj->stkInTop;
    int stkOutTop = obj->stkOutTop;
    while (stkInTop >= 0) {
        obj->stkOut[++stkOutTop] = obj->stkIn[stkInTop--];
    }
    int top = obj->stkOut[stkOutTop--];
    while (stkOutTop >= 0) {
        obj->stkIn[++stkInTop] = obj->stkOut[stkOutTop--];
    }
    obj->stkInTop = stkInTop;
    obj->stkOutTop = stkOutTop;
    return top;
}

int myQueuePeek(MyQueue* obj) {
    return obj->stkIn[0];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->stkInTop == -1;
}

void myQueueFree(MyQueue* obj) {
    obj->stkInTop = -1;
}
    
    