#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node {
	struct node *left;
	int data;
	struct node *right;
}node;

typedef node* bt;

void init_bt(bt *t);
void insert_bt(bt *t, int d);
void inorder_bt(bt t);