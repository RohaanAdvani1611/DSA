#define len 20
typedef struct node{
    int bf;
    char month[len];
    struct node *left, *right, *parent;
}node;

typedef node *AVL;

void initAVL(AVL *t);
void insertNode(AVL *t, char mon[len]);
int removeNode(AVL *t, char mon[len]);
void traverse(AVL t);
void destroyTree(AVL *t);

void adjust_bf(AVL *t, AVL *p, int side);
void LLrotate(AVL *t,node *i);
void LRrotate(AVL *t,node *i);
void RRrotate(AVL *t,node *i);
void RLrotate(AVL *t,node *i);
