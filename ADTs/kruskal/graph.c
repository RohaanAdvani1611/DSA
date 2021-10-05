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
    return;
}

edge* kruskals(graph G){
    int d = G.n;
    
    edge *E = (edge*)malloc(sizeof(edge) * (d-1));
    //Build set & initialize to -1
    int *set = (int*)malloc(sizeof(int)*d);
    for (int i = 0; i < d; i++)
        set[i] = -1;
    
    //array for non decreasing order of edges
    edge* edges = (edge*)malloc(sizeof(edge) * (d*d));
    //copy values from graph to array
    int k = 0;
    for (int i = 0; i < d; i++)
        for (int j = i ; j < d; j++)
            if(G.A[i][j]){
                edges[k].src = i;
                edges[k].dest = j;
                edges[k].weight = G.A[i][j];
                k++;
            }
    //sort the array in order to access edges of minimum weight first
    bubbleSort(edges, k);
    
    int count1 = 0, x, y, m, n, wx, wy, count2 = 0;
    //Max number of edges in min spanning tree is d-1
    while (count2 < d - 1){
        x = edges[count1].src;
        y = edges[count1].dest;
        m = x;
        n = y;
        //parent of u
        while (set[m] >= 0)
            m = set[m];
        //parent of v
        while (set[n] >= 0)
            n = set[n];
        //If parents equal cycle exists thus m != n
        if ( m != n) {
            //union of subsets
            wx = -1 * set[m];
            wy = -1 * set[n];
            if (wx == wy || wx > wy){
                set[n] = m;
                set[m] -= wy;
            }
            else{
                set[m] = n;
                set[n] -= wx;
            }
            //Add edge to array of edges for minimum spanning tree
            E[count2++] = edges[count1];
        }
        //otherwise discard incase cycle detected
        count1++;
    }  
    return E;
}

// A function to implement bubble sort
void bubbleSort(edge* arr, int n){
    int i, j;
    for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++) 
            if (arr[j].weight > arr[j+1].weight)
                swap(&arr[j], &arr[j+1]);
    return;
}

void swap(edge *e1, edge *e2){
    edge temp = *e1;
    *e1 = *e2;
    *e2 = temp;
    return;
}
