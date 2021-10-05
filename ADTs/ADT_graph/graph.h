#define Max 5

typedef struct graph {
    int a[Max][Max];
    int n;
} graph;

void initg(graph *g, char *filename);
void printGraph(graph *g);
void dfs(graph *g, int x);
void bfs(graph *g, int x);
void prim(graph g, int start);