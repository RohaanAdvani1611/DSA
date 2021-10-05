
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include "list.h"



void init(sparse *l) {
    *l = NULL;
    return;
}

void append(sparse *l, int d,int r,int c){
    node *p, *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode){
        newnode->r = r;
        newnode->c = c;
        newnode->data = d;
        newnode->next = NULL;
    }
    else return;
    if(*l == NULL){
        *l = newnode;
        return;
    }
    p = *l;
    while(p -> next) {
       p = p->next;
    }
    p->next = newnode;
    return;
}

void get_array_from_txt(FILE **fp,int p[MROW][MCOL]){

    if(fscanf(*fp, "%d", &row) != 1)
        exit(1);
    if(fscanf(*fp, "%d", &col) != 1)
       exit(1);

    for(int i=0;i<row; i++)
        for(int j=0; j<col; j++)
            if(fscanf(*fp, "%d", &p[i][j]) != 1)
                exit(1);
}

void get_list_from_matrix(int p[MROW][MCOL],sparse *l,int row,int col){
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            if  (p[i][j]!=0){
                append(l,p[i][j],i,j);
            }
        }
    }
    return ;
}

void traverse(sparse l){
    node *p = l;
    while (p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return ;
}

void print(int p[MROW][MCOL]){
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void addition(sparse *r,sparse l1,sparse l2){
    node *p = l1;
    node *q = l2;

    while (p || q){
        if (p == NULL){
            p = (node*)malloc(sizeof(node));
            p->data = INT_MAX;
            p->r = INT_MAX;
            p->c = INT_MAX;
            p->next = NULL;
        }
        if (q == NULL){
            q = (node*)malloc(sizeof(node));
            q->data = INT_MAX;
            q->r = INT_MAX;
            q->c = INT_MAX;
            q->next = NULL;
        }
        if (p->r == q->r){

            if(p->c == q->c){
                append(r,p->data + q->data,p->r,p->c);
                p = p->next;
                q = q->next;

            }

            else if (q->c < p->c){
                append(r,q->data,q->r,q->c);
                q = q->next;
            }

            else {
                append(r,p->data,p->r,p->c);
                p = p->next;
            }

        }

        else if (q->r < p->r){
            append(r,q->data,q->r,q->c);
            q = q->next;
        }

        else {
            append(r,p->data,p->r,p->c);
            p = p->next;
        }

    }

}

void subtract(sparse *r,sparse l1,sparse l2){
    node *p = l1;
    node *q = l2;

    while (p || q){
        if (p == NULL){
            p = (node*)malloc(sizeof(node));
            p->data = INT_MAX;
            p->r = INT_MAX;
            p->c = INT_MAX;
            p->next = NULL;
        }
        if (q == NULL){
            q = (node*)malloc(sizeof(node));
            q->data = INT_MAX;
            q->r = INT_MAX;
            q->c = INT_MAX;
            q->next = NULL;
        }
        if (p->r == q->r){

            if(p->c == q->c){
                append(r,p->data - q->data,p->r,p->c);
                p = p->next;
                q = q->next;

            }

            else if (q->c < p->c){
                append(r,-1*q->data,q->r,q->c);
                q = q->next;
            }

            else {
                append(r,p->data,p->r,p->c);
                p = p->next;
            }

        }

        else if (q->r < p->r){
            append(r,-1*q->data,q->r,q->c);
            q = q->next;
        }

        else {
            append(r,p->data,p->r,p->c);
            p = p->next;
        }

    }

}

void print_sparse_into_txt(FILE **f,sparse l){
    node *p = l;
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            if (i==p->r && j==p->c){
                fprintf(*f,"%d ",p->data);
                p = p->next;
            }
            else
                fprintf(*f,"0 ");
            if (p == NULL)
                p = l;
        }
        fprintf(*f,"\n");
    }
    return ;
}



