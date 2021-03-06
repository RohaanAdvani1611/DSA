#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void inits(stack *s,int length){
    s->top = -1;
    s->len = length;
    s->a = (int*)malloc(sizeof(int)*length);
}

void push(stack *s,int data){
    if (s->top == s->len - 1)
        return ;
    s->top++;
    s->a[s->top] = data;
    return ;
}

int pop(stack *s){
    if (s->top == -1)
        return 0;
    int p;
    p = s->a[s->top];
    s->a[s->top] = (int) NULL;
    s->top--;
    return p;
}

int peek(stack s){
    if (s.top == -1)
        return 0;
    return s.a[s.top];
}

int isFulls(stack s) {
    if(s.top == s.len-1)
        return 1;
    else
        return 0;
}

int isEmptys(stack s) {
    if (s.top == -1)
        return 1;
    else
        return 0;
}