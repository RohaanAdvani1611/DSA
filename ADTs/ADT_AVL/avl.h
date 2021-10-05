/ node
// ADT avl tree

typedef struct node {
    int key,bf;
    struct node *left, *right, *parent;
}node;

typedef node* AVLTree;

void init_AVL(AVLTree *t);
void insert_AVL(AVLTree *t, int d);
void inorder_AVL(AVLTree t);
int height_AVL(AVLTree t);
void remoov_AVL(AVLTree *t,int d);
node* search_AVL(AVLTree t, int d);