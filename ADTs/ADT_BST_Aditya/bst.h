


/*
typedef struct stacknode{
    int key;
    struct stacknode *left, *right;
}stacknode;
*/
typedef struct node{
    int key;
    struct node *left,*right;
}node;

typedef node* bst;

typedef struct stack {
    node *arr;
    int top;
    int size;
}stack;

typedef struct queue{
    node *arr;
    int front,rear,size;
}queue;


void inits(stack *s,int size);
void push(stack *s, node n);
node pop(stack *s);
node peek (stack s);
int isFull(stack s);
int isEmpty(stack s);


int isFullq(queue q);
int isEmptyq(queue q);
void enqueue(queue *q, node item) ;
node dequeue(queue *q);

