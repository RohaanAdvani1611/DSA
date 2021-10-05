#include <stdio.h>
#include "graph.h"

int main(){
    printf("KRUSKALS MINIMUM SPANNING TREE ALGORITHM : \n\n");
    graph G1, G2;
    //Example 1
    initGraph(&G1, "Q1.txt");
    printf("Graph 1 is as follows : \n");
    printGraph(G1);
    printf("\n\nEdges for the minimum spanning tree are as follows : \n");
    edge *ans1 = kruskals(G1);
    printf("Source--(Weight)--Destination\n");
    for (int i = 0; i < G1.n - 1; i++)
        printf("%d--(%d)--%d\n", ans1[i].src, ans1[i].weight, ans1[i].dest);
    
    printf("\n\n");
    //Example 2
    initGraph(&G2, "Q2.txt");
    printf("Graph 2 is as follows : \n");
    printGraph(G2);
    printf("\n\nEdges for the minimum spanning tree are as follows : \n");
    edge *ans2 = kruskals(G2);
    printf("Source--(Weight)--Destination\n");
    for (int i = 0; i < G2.n - 1; i++)
        printf("%d--(%d)--%d\n", ans2[i].src, ans2[i].weight, ans2[i].dest);
    return 0;
}