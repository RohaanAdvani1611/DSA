#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"
#include "Queue.h"

void initg(graph *g, char *filename){
    int x;
    FILE *f;
    int i, j;
    f = fopen(filename, "r");
    if(f == NULL) {
        printf("File can't open");
        return;
    }
    fscanf(f, "%d", &x);
    g->n = x;
    for(i = 0; i < x; i++)
        for(j = 0; j < x; j++)
            fscanf(f, "%d", &(g->a[i][j]));
    return;
}

void printGraph(graph *g){
    for(int i = 0; i < g->n; i++) {
        for(int j = 0; j < g->n; j++)
            printf("%d ", (g->a[i][j]));
        printf("\n");
    }
    return;
}

void dfs(graph *g, int x){
    int v, flag = 0;
    int *visited = (int*)calloc(g->n, sizeof(int));
    for(int i = 0; i < g->n; i++)
        printf("\n%d ", visited[i]);
    stack s;
    inits(&s, 20);
    push(&s, x);
    printf("\n%d - ", x);
    visited[x] = 1;
    while(!isEmptys(s)) {
        v = peek(s);
        for(int j = 0; j < g->n; j++){
            flag = 0;
            if(g->a[v][j] == 1 && !visited[j]){
                push(&s, j);
                printf("%d - ", j);
                visited[j] = 1;
                flag = 1;
                break;
            }
        }
        if(!flag)
            pop(&s);
    }
    return;
}

void bfs(graph *g, int x){
    int *visited = (int*)calloc(g->n, sizeof(int));
    queue q;
    initq(&q, 20);
    enqueue(&q, x);
    printf("\n%d - ", x);
    visited[x] = 1;
    int v;
    while(!isEmptyq(q)){
        v = dequeue(&q);
        for(int j = 0; j < g->n; j++){
            //flag = 0;
            if(g->a[v][j] == 1 && !visited[j]){
                enqueue(&q, j);
                printf("%d - ", j);
                visited[j] = 1;
                //flag = 1;
                break;
            }
        }
    }
    return;
}