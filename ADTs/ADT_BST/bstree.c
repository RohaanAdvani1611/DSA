#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "bstree.h"

//Tree Functions
void init_bst(bst *t) {
	*t = NULL;
	return;
}

void insert_bst(bst *t, int d) {
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
	node *p, *q = NULL;
	p = *t;
	while(p) {
		q = p;
		if(p->data == d) {
			free(nn);
			return;
		}
		if(d < p->data) 
			p = p->left;
		else 
			p = p->right;
	}
	if(d < q->data) 
		q->left = nn;
	else 
		q->right = nn;
	return;
}

void inorder_bst(bst t) {
	if(!t) 
		return;
	inorder_bst(t->left);
	printf("%d ", t->data);
	inorder_bst(t->right);
}

void inorder_nonrecursive(bst t){
    node *p;
    stack s;

    inits(&s, 20);
    if (!(t))
        return ;
    p = t;
    while (p || !isEmptys(s)){
        while (p){
            push(&s, *p);
            p = p->left;
        }
        p = &(s.arr[s.top]);
        pop(&s);
        printf("%d ",p->data);
        p = p->right;
    }
}

void preorder_bst(bst t){
    if(!t) 
		return;
	printf("%d ", t->data);
	preorder_bst(t->left);
	preorder_bst(t->right);
}

void postorder_bst(bst t){
    if(!t) 
		return;
	postorder_bst(t->left);
	postorder_bst(t->right);
	printf("%d ", t->data);
}

int depth(bst t){
    if(!t) 
		return -1;
	int l,r;
	l = depth(t->left);
	r = depth(t->right);
	if (l>r)
	    return ++l;
	else
	    return ++r;
}

int count_node(bst t){
    if(!t) 
		return 0;
	return 1+count_node(t->left)+count_node(t->right);
}

int count_leaves(bst t){
    if(!t) 
		return 0;
	if (t->left==NULL && t->right==NULL)
	    return 1;
	return count_leaves(t->left) + count_leaves(t->right);
}

void level_order(bst t){
    node *p = t;
    if (p == NULL)
        return;
    queue q;
    initq(&q, 20);
    enqueue(&q, *p);
    node n;
    while (!(isEmptyq(q))){
        n = dequeue(&q);
        printf("%d ", n.data);
        if (n.left)
            enqueue(&q, *n.left);
        if (n.right)
            enqueue(&q, *n.right);
    }
    return;
}

int isFull_bst(bst t){
    if(!t) 
		return 1;
	if((!t->left && t->right) || (t->left && !t->right))
	    return 0; //Only 1 child
	if(!t->left && !t->right)
	    return 1;
	return isFull_bst(t->left) && isFull_bst(t->right);
}

int isComplete_bst(bst t){
    if (!(t))
        return 1;
    if (!(isFull_bst(t)))
        return 0;
    if (depth(t->left) != depth(t->right))
        return 0;
    else
        return isComplete_bst(t->left) && isComplete_bst(t->right);
}

node* search(bst t, int d){
    node *p = t;
    //empty bstree
    if(!p) return p;
    while(p){
        if (p->data == d)
            return p;
        if (p->data > d)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}

void remov(bst *t, int d){
    int side;
    if(!t) 
		return;
	node *p, *q=NULL;
	p = *t;
	while(p) {
		q = p;
		if(p->data == d) 
			break;
		if(d < p->data) {
			p = p->left;
			side=0;
		}
		else {
			p = p->right;
			side=1;
		}

	}
	//If p is null d not found
	if(!p)
	    return;
		//leaf
	if(!p->left && 1p->right){
	    if(side)
	        q->right=NULL;
	    else
	        q->left=NULL;
	    free(p);
	    return;
	}
}

//Stack Funcs
void inits(stack *s, int t) {
    s->size = t;
    s->arr = (node*)malloc(sizeof(node)* t);
    s->top = -1;
}

void push(stack *s, node p) {
    if(isFulls(*s)) {
        return;
    }
    s->arr[++s->top] = p;
    return;
}

node pop(stack *s){
     node n;
     n.data = INT_MIN;
     n.left = NULL;
     n.right = NULL;
     if(isEmptys(*s)){
        return n;
     }
     node r = s->arr[s->top];
     s->top--;
     return r;
}

node peek (stack s) {
     node n;
     n.data = INT_MIN;
     n.left = NULL;
     n.right = NULL;
    if(isEmptys(s)){
        return n;
      }
    return s.arr[s.top];
 }

int isFulls(stack s){
    if(s.top == s.size-1)
        return 1;
    else
        return 0;
}

int isEmptys(stack s){
    if(s.top == -1)
        return 1;
    else
        return 0;
}

//Queue Functions
void initq(queue *q, int len){
    q->size = len;
    q->front = 0;
    q->rear = 0;
    q->arr = (node*)malloc(sizeof(node)*len);
}

int isFullq(queue q) {
    return (q.rear == q.size);
}

// Queue is empty when size is 0
int isEmptyq(queue q) {
    return (q.rear == 0);
}

void enqueue(queue *q, node item) {
    if (isFullq(*q))
        return;

    q->rear = (q->rear + 1)
                  % q->size;
    q->arr[q->rear] = item;
    return ;
}

node dequeue(queue *q){
    node r = {INT_MIN, NULL, NULL};
    if (isEmptyq(*q))
        return r;
    q->front = (q->front + 1)
                   % q->size;
    node item = q->arr[q->front];
    return item;
}

