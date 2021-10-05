#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    graph g, g1;
    initg(&g, "adjmat1.txt");
    printGraph(&g);
    dfs(&g, 0);
    //bfs(&g, 1);
    printf("\n");
    initg(&g1, "adjmat2.txt");
    printGraph(&g1);
    dfs(&g1, 0);
    //bfs(&g1, 0);
    return 0;
}
