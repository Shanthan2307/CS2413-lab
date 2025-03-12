#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* stack1;
    int* stack2;
    int top1;
    int top2;
    int size;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->size = 100; // Fixed size, can be dynamic if needed
    queue->stack1 = (int*)malloc(queue->size * sizeof(int));
    queue->stack2 = (int*)malloc(queue->size * sizeof(int));
    queue->top1 = -1;
    queue->top2 = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++(obj->top1)] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) { // Transfer elements from stack1 to stack2
        while (obj->top1 != -1) {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return (obj->top2 == -1) ? -1 : obj->stack2[(obj->top2)--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return (obj->top2 == -1) ? -1 : obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}
