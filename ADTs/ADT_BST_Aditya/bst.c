#include <stdlib.h>
#include "bst.h"
#include "limits.h"


void init(bst *t){
    *t = NULL;
    return ;
}

void insert(bst *t, int data){
    node *nn = (node*)malloc(sizeof(node));
    if (!(nn))
        return ;
    nn->key = data;
    nn->left = NULL;
    nn->right = NULL;

    if (*t == NULL){
        *t = nn;
        return ;
    }

    node *p = *t;
    node *q = NULL;

    while (p){
        q = p;
        if (data < p->key)
            p = p->left;
        else if(data > p->key)
            p = p ->right;
        else{
            free(nn);
            return ;
        }
    }
    if (data < q->key)
        q->left = nn;
    else{
        q->right = nn;
    }
    return ;
}

void inorder(bst t){
    if (t == NULL)
        return ;
    inorder(t->left);
    printf("%d ",t->key);
    inorder(t->right);
    return;
}

void preorder(bst t){
    if (t == NULL)
        return ;
    printf("%d ",t->key);
    preorder(t->left);
    preorder(t->right);
    return ;
}

void postorder(bst t){
    if (t == NULL)
        return ;
    postorder(t->left);
    postorder(t->right);
    printf("%d ", t->key);
    return ;
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
        printf("%d ",p->key);
        p = p->right;
    }
}
void preorder_tree(bst t){
    printf("\n");
    node *p = t;
    if (p == NULL)
        return ;
    stack s;
    inits(&s, 20);
    while (p){
        printf("%d ", p->key);
        push(&s, *p);
        p = p->left;

        while (!(p)){
            node temp = pop(&s);
            p = temp.right;
        }
        if (p->key == INT_MIN)
            break;
    }
    return ;
}

void level_order(bst t){
    node *p = t;
    if (p == NULL)
        return ;
    queue q;
    initq(&q, 20);
    enqueue(&q, *p);
    node n;
    while (!(isEmptyq(q))){
        n = dequeue(&q);
        printf("%d ", n.key);
        if (n.left)
            enqueue(&q, *n.left);
        if (n.right)
            enqueue(&q, *n.right);
    }
    return ;
}

int depth(bst t){
    if (!(t))
        return -1;

    else{
        int leftdepth = depth(t->left);
        int rightdepth = depth(t->right);
        if (leftdepth > rightdepth)
            return leftdepth + 1;
        else
            return rightdepth + 1;
    }

}

int count(bst t){
    if (!(t))
        return 0;
    return 1 + count(t->left) + count(t->right);
}


int count_leafnode(bst t){
    if (!(t))
        return 0;
    if (!(t->left) && !(t->right))
        return 1;
    return count_leafnode(t->left) + count_leafnode(t->right);
}

int isFullt(bst t){
    if (!(t))
        return 1;
    if ((t->left && !(t->right)) || (!(t->left) && t->right))
        return 0;
    else
        isFullt(t->left) && isFullt(t->right);
}

int isComplete(bst t){
    if (!(t))
        return 1;
    if (!(isFullt(t)))
        return 0;
    if (depth(t->left) != depth(t->right))
        return 0;
    else
        return isComplete(t->left) && isComplete(t->right);
}


node *search(bst t, int d){
    node *p = t;
    if (p == NULL)
        return ;
    while (p){
        if (d==p->key)
            return p;
        if (d < p->key)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}

void remov(bst *t, int d){

}

//STACK FUNCTIONS


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
     n.key = INT_MIN;
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
     n.key = INT_MIN;
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




