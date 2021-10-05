#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "graph.h"

void initGraph(graph *G, char *filename){
    FILE *fp = fopen(filename, "r");
    if (!fp)
        return ;
    int n ;
    fscanf(fp, "%d", &n);
    G->n = n;
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0 ;j < n; j++)
            fscanf(fp, "%d", &G->A[i][j]);
    return ;    
}

void printGraph(graph G){
    for (int i = 0; i < G.n; i++){
        for (int j = 0; j < G.n; j++)
            printf("%d ", G.A[i][j]);
        printf("\n");
    }
}

void BellmanFord(graph G, int x){
    int flag = 0;
    int d = G.n;
    //Declare output array which displays distances from source to each vertex
    //Initialize distances from source to all vertices as infinite
    //Distance to source itself as 0
    int *dist = (int*)malloc(sizeof(int) * d);
    for (int i = 0 ;i < d; i++)
        dist[i] = INT_MAX;
    dist[x] = 0;
    //Do following |V|-1 times where |V| is the number of vertices in given graph
    //Do following for each edge u-v 
    //If dist[v] > dist[u] + weight of edge uv, then update dist[v] 
    //dist[v] = dist[u] + weight of edge uv
    for(int count = 0; count < d; count++)
        for (int i = 0; i < d; i++)
            for (int j = 0; j < d; j++)
                if (G.A[i][j] && G.A[i][j] + dist[i] < dist[j])
                    dist[j] = G.A[i][j] + dist[i];
    //Check for negative weight cycles for each edge
    for (int i = 0; i < d; i++)
        for (int j = 0; j < d; j++)
            if (G.A[i][j] && G.A[i][j] + dist[i] < dist[j]){
                printf("Graph contains negative weight cycle");
                flag = 1;
            }
    //Print Array if no negative weight cycle
    if(flag == 0)
        for (int i = 0; i < G.n; i++)
            printf("%d ", dist[i]);
    return;
}

