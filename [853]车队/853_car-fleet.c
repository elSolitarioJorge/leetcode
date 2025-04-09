//思路1
typedef struct {
    int pos;
    double time;
} Car;

int cmp (const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c2->pos - c1->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    Car cars[positionSize];
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }
    qsort(cars, positionSize, sizeof(Car), cmp);
    int ans = 1;
    for (int i = 1; i < positionSize; i++) {
        if (cars[i].time > cars[i - 1].time) {
            ans++;
        } else {
            cars[i].time = cars[i - 1].time;
        }
    }
    return ans;
}
//思路2
typedef struct {
    int pos;
    double time;
} Car;

int cmp (const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c1->pos - c2->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    Car cars[positionSize];
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }
    qsort(cars, positionSize, sizeof(Car), cmp);
    int stack[positionSize];
    int top = -1;
    for (int i = 0; i < positionSize; i++) {
        double t = cars[i].time;
        while (top >= 0 && t >= cars[stack[top]].time) {
            top--;
        }
        stack[++top] = i;
    }
    return top + 1;
}
    
    