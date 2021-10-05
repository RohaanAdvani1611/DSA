//Using Union as either operator or operand can be stored in mem loc
typedef union expression{
    int digit;
    char oper;
}expression;

typedef struct node{
    expression key;
    struct node *left, *right;
}node;

typedef node* ET;

void initTree(ET *t, char *str);
void traverse(ET t);
node* compute(ET t, node *root);

//Helper Functions
node create_intnode(int data);
node create_charnode(char data);
int precendence(char op);

//Operator Stack Functions
typedef struct cstack{
    char *A;
    int len;
    int top;
}cstack;

void cinit(cstack *s,int length);
void cpush(cstack *s,char data);
char cpop(cstack *s);
int cisFull(cstack s) ;
int cisEmpty(cstack s);
char cpeek(cstack s);

//Number Stack Functions
typedef struct nstack{
    node *arr;
    int size;
    int top;
}nstack;

void ninit(nstack *s, int t);
void npush(nstack *s, node p);
node npop(nstack *s);
node *npeek (nstack s) ;
int nisFull(nstack s);
int nisEmpty(nstack s);