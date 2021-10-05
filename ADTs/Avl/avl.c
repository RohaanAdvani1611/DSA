#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "avl.h"

void initAVL(AVL *t){
    *t = NULL;
    return;
}

void insertNode(AVL *t, char mon[len]) {
    node *nn = (node*)malloc(sizeof(node));
    if(!nn)
        return;
    strcpy(nn->month, mon);
    nn->left = NULL;
    nn->right = NULL;
    nn->parent = NULL;
    nn->bf = 0;
    //tree is empty
    if(*t == NULL){
        *t = nn;
        return;
    }
    //find the location to insert the nn node
    //use p and q pointers, p points to the root node, q points to parent of p
    node *p, *q = NULL;
    p = *t;
    while(p){
        q = p;
        if(strcmp(p->month, mon) == 0){
            free(nn);
            return;
        }
        if(strcmp(p->month, mon) > 0){
            //p->bf++;
            p = p->left;
        }
        else{
           //p->bf--;
           p = p->right;
        }
    }
    if(strcmp(q->month, mon) > 0)
        q->left  = nn;
    else
        q->right = nn;

    nn->parent = q;
    //setting of bf from nn to root to be done now
    p = nn->parent;
    q = nn;
    node *i = NULL;
    while(p){
        if(strcmp(p->month, q->month) > 0)
            p->bf++;
        else
            p->bf--;
        if(p->bf == 0)
            break;
        q = p;
        if(abs(p->bf) > 1) // bf 2 or -2 imbalanced node
            if(!i)
                i = p;
        p = p->parent;
    }
    // Determine the type type of imbalance
    if(i){
        printf("\nImbalance at: %s - %d\n", i->month, i->bf);
        if(i->bf >= 2){
            if(strcmp(i->left->month, mon) > 0){
                printf("LLrotate required\n");
                LLrotate(t,i);
            }
            else{
                printf("\nLRrotate is required\n");
                LRrotate(t,i);
            }
        }
        else {
            if(strcmp(i->right->month, mon) > 0){
                printf("\nRLrotate is required\n");
                RLrotate(t,i);
            }
            else{
                printf("\nRRrotate is required\n");
                RRrotate(t,i);
            }
        }
    }
    return ;
}

int removeNode(AVL *t, char mon[len]){
    if(!t) //Tree is empty
        return 0;
    node *p, *q = NULL;
    p = *t;
    int side;
    while(p){
        //if(p->key == key)
        if(strcmp(p->month, mon) == 0)
            break;
        //else if(p->key > key)
        else if(strcmp(p->month, mon) > 0){
            side = 0;
            q = p;
            p = p->left;
        }
        //else if(p->key < key)
        else if(strcmp(p->month, mon) < 0){
            side = 1;
            q = p;
            p = p->right;
        }
    }
    if(!p) //node to be deleted is not there in the tree
        return 0;
    /* The node is a leaf node */
    if(!p->left && !p->right){
        if(!q){ //The node is the root itself
            *t = NULL;
            free(p);
            return 1;
        }
        if(!side)
            q->left = NULL;
        else
            q->right = NULL;
        adjust_bf(t, &q, side);
        return 1;
    }

    /* The node has 1 child */
    //Left child
    if(p->left && !p->right){
        if(!q){ //Meaning p is the root node with only left child
            *t = p->left;
            free(p);
            return 1;
        }
        if(!side){
            q->left = p->left;
            p->left->parent = q;
        }
        else{
            q->right = p->left;
            p->left->parent = q;
        }
        adjust_bf(t, &q, side);
        return 1;
    }
    //Only Right child
    if(!p->left && p->right){
        if(!q){ //Meaning p is the root node with only right child
            *t = p->right;
            free(p);
            return 1;
        }
        if(!side){
            q->left = p->right;
            p->right->parent = q;
        }
        else{
            q->right = p->right;
            p->right->parent = q;
        }
        adjust_bf(t, &q, side);
        free(p);
        return 1;
    }
    //Two children nodes
    if (p->right && p->left){
        node *r = NULL, *s = NULL;//r as parent of s like q was parent of p
        //go to left then to the rightmost node
        r = p->left;
        //p->bf--;
        while(r->right){
            s = r;
           // s->bf++;
            r = r->right;
        }
        //r is null //copy s value to p //p->left as null &free s
        if(!s){
            strcpy(p->month, r->month);
            //p->key = s->key;
            p->left = r->left;
            if(r->left)
                r->left->parent = p;
            side = 0;
            adjust_bf(t, &p, side);
            free(r);
            return 1;
        }
        //copy key of node s to p  //make right of r as null  //free s
        //p->key = s->key;
        strcpy(p->month, r->month);
        s->right = r->left;
        if(r->left)
            r->left->parent = s;
        free(r);
        side = 1;
        adjust_bf(t, &s, side);
        return 1;
    }
    return 0;
}

void traverse(AVL t){
    if(!t)
        return;
    traverse(t->left);
    printf("%s  %d \n",t->month,t->bf);
    traverse(t->right);
    return;
}

void destroyTree(AVL *t){ // to delete all nodes of a tree
    node *p = *t;
    if(p == NULL)
        return;
    destroyTree(&(p->left));
    destroyTree(&(p->right));
    free(p);
    *t = NULL;
    return;
}

void adjust_bf(AVL *t, AVL *m_node, int side){
    node *p = *m_node;
    node *i = NULL;
    while(p){
        if(!p->bf){ // The tree was already balanced ... so removing 1 child will not affect the height
            p->bf += (!side) ?  -1 : 1;
            break;
        }
        p->bf += (!side) ?  -1 : 1;
        if(abs(p->bf) > 1){
            i = p;
            break;
        }
        if(p->parent){
            //side = (p->key > p->parent->key) ? 1 : 0;
            if(strcmp(p->month, p->parent->month) > 0)
                side = 1;
            else
                side = 0;
        }
        p = p->parent;
    }
    /* Imbalance found */
    if(i){
       printf("\nImbalance at the point : %s\n", i->month);
       if(i->bf >= 2){
            printf("Left rotation\n");
            if(i->left->bf > 0)
                LLrotate(t, i);
            else
                LRrotate(t, i);
       }
       else{
            printf("Right rotation\n");
            if(i->right->bf < 0)
                RRrotate(t, i);
            else
                RLrotate(t, i);
       }
    }
    return;
}

void LLrotate(AVL *t,node *i){
    node *a , *b;
    a = i->left;
    b = a->right;
    a->parent = i->parent;
    if(i->parent){
        if(i->parent->left == i){
            i->parent->left = a;
            i->parent->bf--;
        }
        else{
            i->parent->right = a;
            i->parent->bf++;
        }
    }
    else
        *t = a;
    a->right = i;
    i->parent = a;
    i->left = b;
    if(b){
        b->parent = i;
        //i->bf = b->bf + 1;
    }
    i->bf = i->bf - a->bf - 1;
    a->bf = 0 ;
    return;
}

void LRrotate(AVL *t,node *i){
    node *a = i->left;
    node *b = a->right;
    b->left = a;
    a->right  = NULL;
    a->parent = b;
    b->parent = i;
    i->left = b;
    b->bf = -a->bf;
    a->bf++;
    LLrotate(t,i);
    return;
}

void RRrotate(AVL *t, node *i){
    node *a , *b;
    a = i->right;
    b = a->left;
    a->parent = i->parent;
    if(i->parent){
        if(i->parent->left == i){
            i->parent->left = a;
            i->parent->bf--;
        }
        else{
            i->parent->right = a;
            i->parent->bf++;
        }
    }
    else
        *t = a;
    a->left = i;
    i->parent = a;
    i->right = b;
    if(b){
        b->parent = i;
        i->bf = 0;
        //i->bf = b->bf + 1;
    }
    else
        i->bf = 0;
    //a->bf = a->left->bf - i->bf;
    i->bf = i->bf + a->bf + 1;
    a->bf = 0 ;
    return;
}

void RLrotate(AVL *t,node *i){
    node *a = i->right;
    node *b = a->left;
    b->right = a;
    a->left  = NULL;
    a->parent = b;
    b->parent = i;
    i->right = b;
    b->bf = -a->bf;
    a->bf--;
    RRrotate(t, i);
    return;
}

