
typedef struct node{
    int MIS;
    char name[20];
    struct node *left, *right, *parent;
}node;

typedef node* bst;

typedef struct stack {
    node *arr;
    int top;
    int size;
}stack;

void initBST(bst *t);
void insertNode(bst *t, int d, char *name);
void removeNode(bst *t, int d);
int search(bst t, int d);
void postorder(bst t);
void Display_Level(bst t, int i);
void destroyTree(bst *t);


void inits(stack *s, int t);
void push(stack *s, node p);
node pop(stack *s);
node peek (stack s);
int isFulls(stack s);
int isEmptys(stack s);
