#include <stdio.h>
#include <stdlib.h>
#include "ass2a.h"
#include "limits.h"

static int root = 0;

void init_bst(bst *t, int n){
    t->A = (int*)malloc(sizeof(int)*n);
    t->n = n;
    for (int i = 0;i < n; i++)
        t->A[i] = INT_MIN;
    return ;
}

void insert_bst(bst *t, int data){
    int i = 0;
    if (t->A[i] == INT_MIN){
        t->A[i] = data;
        return;
    }

    while (i < t->n && t->A[i] != INT_MIN){
        if (t->A[i] == data)
            return ;
        if (data < t->A[i])
            i = 2*i + 1;
        else
            i = 2*i + 2;
    }
    if (i < t->n){
        t->A[i] = data;
        return ;
    }
    return ;
}

void recursive_traverse(bst t, int i){
    printf("\nInorder: ");
    inorder(t, i);
    printf("\nPreorder: ");
    preorder(t, i);
    printf("\nPostorder: ");
    postorder(t, i);
    return;
}

void inorder(bst t, int i){
    if (t.A[i] == INT_MIN)
        return ;
    inorder(t, 2*i + 1);
    printf("%d ", t.A[i]);
    inorder(t, 2*i + 2);
    return;
}

void preorder(bst t, int i){
    if (t.A[i] == INT_MIN)
        return ;
    printf("%d ", t.A[i]);
    preorder(t, 2*i + 1);
    preorder(t, 2*i + 2);
    return;
}

void postorder(bst t, int i){
    if (t.A[i] == INT_MIN)
        return ;
    postorder(t, 2*i + 1);
    postorder(t, 2*i + 2);
    printf("%d ", t.A[i]);
    return;
}

int isComplete(bst t, int i, int n){
    if (t.A[i] == INT_MIN)
        return 1;
    if (i >= n)
        return 0;
    return (isComplete(t, 2*i + 1, n) && isComplete(t, 2*i + 2, n));
}
