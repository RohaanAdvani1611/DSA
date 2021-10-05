#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node {
	struct node *left;
	int data;
	struct node *right;
}node;

typedef struct stack {
    node *arr;
    int top;
    int size;
}stack;

typedef struct queue{
    node *arr;
    int front,rear,size;
}queue;

typedef node* bst;

//Tree
void init_bst(bst *t);
void insert_bst(bst *t, int d);
void inorder_bst(bst t);
void inorder_nonrecursive(bst t);
void preorder_bst(bst t);
void postorder_bst(bst t);
int depth(bst t);
int count_node(bst t);
int count_leaves(bst t);
void level_order(bst t);
int isFull_bst(bst t); //Every node has 2 children
int isComplete_bst(bst t);
node* search(bst t, int d);
void remov(bst *t, int d);

//Stack
void inits(stack *s,int size);
void push(stack *s, node n);
node pop(stack *s);
node peek(stack s);
int isFulls(stack s);
int isEmptys(stack s);

//Queue
void initq(queue *q, int len);
int isFullq(queue q);
int isEmptyq(queue q);
void enqueue(queue *q, node item) ;
node dequeue(queue *q);