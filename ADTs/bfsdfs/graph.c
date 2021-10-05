#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stack.h"
#include "graph.h"
#include "Queue.h"

void initGraph(graph *G, int n){
    G->n = n;
    G->A = (node**)malloc(sizeof(node*) * n);
    for(int i = 0; i < n ; i++){        
        G->A[i] = 0;
    }
    return ;
}

void matrix_to_list(graph *G){
    FILE *f;
    //Text file has weighted undirected graph as Adjacency Matrix
    f = fopen("Adjmatrix.txt", "r");
    int w ,size;
    fscanf(f, "%d", &size);
    initGraph(G, size);
    for (int i = 0; i < size; i++){
        for (int j = 0 ; j < size; j++){
            fscanf(f, "%d", &w);
            if (!w)
                continue;
            //Edge i, j of weight w is added to the ajacency list 
            addEdge(G, i, j, w);
        }
    }
    return;
}

void printGraph(graph G){
    node *p;
    for (int i = 0;i < G.n; i++){        
        printf("%d - ", i);
        p = G.A[i];
        while (p){
            printf("%d (%d) ", p->val, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}

void addEdge(graph *G, int start, int end, int weight){
    if (start < 0 || end > G-> n - 1)
        return;
    node *p = G->A[start];
    node *q = NULL;
    while (p){
        q = p;
        p = p->next;
    }
    if (!q){
        G->A[start] = (node*)malloc(sizeof(node));
        G->A[start]->val = end;
        G->A[start]->weight = weight;
        G->A[start]->next = NULL;
        return ;
    }
    q->next = (node*)malloc(sizeof(node));
    q->next->val = end;
    q->next->weight = weight;
    q->next->next = NULL;
    return ;
}

void dfs(graph G, int x){
    int v, flag = 0;
    int *visited = (int*)calloc(G.n, sizeof(int));
    node *p;
    stack s;
    inits(&s, 20);
    push(&s, x);
    printf("%d - ", x);
    visited[x] = 1; 
    while (!isEmptys(s)){
        v = peek(s);
        p = G.A[v];
        while (p){
            flag = 0;
            if (!visited[p->val]){
                push(&s, p->val);
                printf("%d - ", p->val);
                visited[p->val] = 1;
                flag = 1;
                break;
            }
            p = p->next;
        }
        if (!flag)
            pop(&s);
    }
    return ;
}

void bfs(graph G, int x){
    int *visited = (int*)calloc(G.n, sizeof(int));
    queue q;
    initq(&q, 20);
    enqueue(&q, x);
    printf("%d - ", x);
    visited[x] = 1;
    int v;
    node *p;
    while(!isEmptyq(q)){
        v = dequeue(&q);
        p = G.A[v];
        while (p){
            if (!visited[p->val]){
                enqueue(&q, p->val);
                printf("%d - ", p->val);
                visited[p->val] = 1;
            }
            p = p->next;            
        }
    }
    return;
}
