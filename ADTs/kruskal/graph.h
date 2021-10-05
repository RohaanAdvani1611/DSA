#define MAX 10

typedef struct graph{
    int A[MAX][MAX];
    int n;
}graph;

typedef struct edge{
    int src, dest;
    int weight;
}edge;

void initGraph(graph *G, char *filename);
void printGraph(graph G);
edge* kruskals(graph G);
void bubbleSort(edge* arr, int n);
void swap(edge *e1, edge *e2);

