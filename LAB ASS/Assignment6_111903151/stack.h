typedef struct stack{
    int *a;
    int top;
    int len;
}stack;

void inits(stack *s,int length);
void push(stack *s,int data);
int pop(stack *s);
int peek(stack s);
int isFulls(stack s);
int isEmptys(stack s);
