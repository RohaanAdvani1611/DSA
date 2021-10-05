#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(){
    graph G;
    matrix_to_list(&G);
    printf("\nThe following is the adjacency list : \n");
    printGraph(G);
    printf("DFS of Graph above is as follows : \n");
    dfs(G, 4);
    printf("\nBFS of Graph above is as follows : \n");
    bfs(G, 4);
    return 0;
 }