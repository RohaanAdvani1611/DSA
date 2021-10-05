#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack1queue.h"


void init(st *q, int len) {
    q->s = len;
    q->f = -1;
    q->r = -1;

    q->d = (int *)malloc(sizeof(int)*len);
}

int isFull(st q) {
    if(q.r == q.s-1){
        return 1;
    }
    else
        return 0;
}


int isEmpty(st q) {
    if(q.f == q.r){
        printf("Queue is Empty\n");
        return 1;
    }
    else
        return 0;

}
void push(st *q,int x)
{
    if(!isFull(*q)){
        q->r++;
        q->d[q->r]=x;
        return;
    }
}

int pop(st *q)
{

    int x=INT_MIN;
    if(!isEmpty(*q)){
        shift(q);
        x = q->d [q->f];
    }
    return x;
}

void shift(st *q) {

    int temp = q->d[q->r];
    for(int i = q->r; i > ((q->f) + 1); i--) {
        q->d[i] = q->d[i - 1];
    }
    q->f = q->f + 1;
    q->d[q->f] = temp;
    return;
}

void traverse(st q) {

    if(!isEmpty(q)) {
        for(int i = q.f + 1; i <= q.r; i++) {

            printf("%d ", q.d[i]);
        }
    }
    printf("\n");
    return;
}
int top(st q){
    if(isEmpty(q)) {
        printf("Stack is empty");
    }
    else{
        printf("The top of the stack is:");
        printf("%d\n",q.d[q.r]);
    }
    return 0;
}





