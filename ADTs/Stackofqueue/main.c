#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack1queue.h"

int main() {
    st s1;
    init(&s1, 6);
    push(&s1, 17);
    push(&s1, 78);
    push(&s1, 9);
    push(&s1, 7);
    push(&s1, 19);
    push(&s1, 5);


    traverse(s1);
    int x = pop(&s1);
    printf("Removed element : %d\n", x);
    traverse(s1);
    top(s1);
    int y = pop(&s1);
    printf("Removed element : %d\n", y);
    traverse(s1);
    int z = pop(&s1);
    printf("Removed element : %d\n", z);
    traverse(s1);
    int w = pop(&s1);
    printf("Removed element : %d\n", w);
    traverse(s1);
    int m = pop(&s1);
    printf("Removed element : %d\n", m);
    traverse(s1);
    int n = pop(&s1);
    printf("Removed element : %d\n", n);
    traverse(s1);
    return 0;

}
