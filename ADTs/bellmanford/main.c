#include <stdio.h>
#include "graph.h"

int main(){
    graph G, G1;
    printf("BELLMAN FORD ALGORITHM :\n");
    initGraph(&G, "adjmatrix.txt");
    printf("The example graph is as follows : \n");
    printGraph(G);
    printf("\nThe distance of each vertex from source is as follows : \n");
    BellmanFord(G, 0);
    
    initGraph(&G1, "adjmatrix2.txt");
    printf("\n\nThe test graph for negative weight cycle is as follows : \n");
    printGraph(G1);
    printf("\nThe distance of each vertex from source is as follows : \n");
    BellmanFord(G1, 0);
}