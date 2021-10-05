#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "bt.h"

void init_bt(bt *t) {
	*t = NULL;
	return;
}

void insert_bt(bt *t, int d){
    int choice;
    node *nn = (node*)malloc(sizeof(node));
	if(!nn)
		return;
	nn->left = NULL;
	nn->data = d;
	nn->right = NULL;
	if(*t == NULL) {
		*t = nn;
		return;
	}
	printf("\nInsert node as:");
	printf("\n1. Left Child");
	printf("\n2. Right Child");
	switch(choice){
	    case 1:
	}
}

void inorder_bt(bt t){
    if(!t) 
		return;
	inorder_bt(t->left);
	printf("%d ", t->data);
	inorder_bt(t->right);
}