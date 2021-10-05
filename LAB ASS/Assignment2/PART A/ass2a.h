#include <stdio.h>
#include <stdlib.h>

typedef struct bst{
    int *A;
    int n;
}bst;

typedef struct node{
    int i;
    int data;
}node;

void init_bst(bst *t, int n);
void insert_bst(bst *t, int data);
void recursive_traverse(bst t, int i);
void inorder(bst t, int i);
void preorder(bst t, int i);
void postorder(bst t, int i);
int isComplete(bst t, int i, int n);

