typedef struct{
    int r;
    int f;
    int *d;
    int s;
}st;


void init(st *q,int len);
int isFull(st q);
int isEmpty(st q);
void push(st *q,int x);
int pop(st *q);
void traverse(st q);
void shift(st *q);
int top(st q);



