#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* queue1;
    int* queue2;
    int front1, rear1;
    int front2, rear2;
    int size;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->size = 100; // Fixed size, can be dynamic if needed
    stack->queue1 = (int*)malloc(stack->size * sizeof(int));
    stack->queue2 = (int*)malloc(stack->size * sizeof(int));
    stack->front1 = stack->rear1 = -1;
    stack->front2 = stack->rear2 = -1;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->queue1[++(obj->rear1)] = x;
}

int myStackPop(MyStack* obj) {
    if (obj->rear1 == -1) return -1; // Stack is empty
    
    while (obj->front1 < obj->rear1 - 1) {
        obj->queue2[++(obj->rear2)] = obj->queue1[++(obj->front1)];
    }
    int topElement = obj->queue1[++(obj->front1)];
    
    // Swap queues
    int* tempQueue = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = tempQueue;
    obj->front1 = obj->front2 = -1;
    obj->rear1 = obj->rear2;
    obj->rear2 = -1;
    
    return topElement;
}

int myStackTop(MyStack* obj) {
    if (obj->rear1 == -1) return -1; // Stack is empty
    
    while (obj->front1 < obj->rear1) {
        obj->queue2[++(obj->rear2)] = obj->queue1[++(obj->front1)];
    }
    int topElement = obj->queue1[obj->front1];
    obj->queue2[++(obj->rear2)] = obj->queue1[obj->front1];
    
    // Swap queues
    int* tempQueue = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = tempQueue;
    obj->front1 = obj->front2 = -1;
    obj->rear1 = obj->rear2;
    obj->rear2 = -1;
    
    return topElement;
}

bool myStackEmpty(MyStack* obj) {
    return obj->rear1 == -1;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}
