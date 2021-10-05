typedef struct node{
    int val;
    int weight;
    struct node *next;
}node;

typedef struct graph{
    node **A;
    int n;
}graph;

void initGraph(graph *G, int size);
void matrix_to_list(graph *G);
void printGraph(graph G);
void addEdge(graph *G, int start, int end, int weight);
void dfs(graph G,int x);
void bfs(graph G, int x);