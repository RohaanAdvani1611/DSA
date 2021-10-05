
#define MROW 100
#define MCOL 100

typedef struct node{
    int r;
    int c;
    int data;
    struct node *next;
}node;

typedef node* sparse;

const int row,col;


void init(sparse *l);
void append(sparse *l, int d,int r,int c);
void get_array_from_txt(FILE **fp,int p[MROW][MCOL]);
void get_list_from_matrix(int p[MROW][MCOL],sparse *l,int row,int col);
void traverse(sparse l);
void print(int p[MROW][MCOL]);
void addition(sparse *r,sparse l1,sparse l2);
void subtract(sparse *r,sparse l1,sparse l2);
void print_sparse_into_txt(FILE **f,sparse l);


