#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "bst.h"
#include "string.h"

void initBST(bst *t){
    *t = NULL;
    return ;
}

void insertNode(bst *t, int d, char *name){
    if (!*t){
        node *nn = (node*)malloc(sizeof(node));
        nn->MIS = d;
        strcpy(nn->name, name);
        nn->left = nn->right = nn->parent = NULL;
        *t = nn;//inserting node
        return ;
    }
    node *p = *t;
    if (d < p->MIS){
        insertNode(&p->left, d, name);
        //setting parent
        p->left->parent = p;
        return ;
    }
    else if (d > p->MIS){
        insertNode(&p->right, d, name);
        p->right->parent = p;
        return ;
    }
    return p;
}


void removeNode(bst *t, int d){
    if (!(t))
        return;
    node *p, *q;
    int side;
    //searching loop
    p = *t;
    q = NULL;
    while (p){
        if (d == p->MIS)
            break;
        q = p;
        if (d < p->MIS){
            p = p->left;
            side = 0;
        }
        else{
            p = p->right;
            side = 1;
        }
    }
    // not found
    if (!(p))
        return ;
    //leaf case
    if (!p->left && !p->right){
        if (!(q)){
            *t = NULL;
            free(p);
            return ;
        }
        if (side)
            q->right = NULL;
        else
            q->left = NULL;
        free(p);
        return ;
    }
    //one child

    //left child
    if (p->left && !p->right){
        //p is root
        if(!q){
            *t = p->left;
            free(p);
            return ;
        }

        if (side == 0)
            q->left = p->left;
        if (side)
            q->right = p->left;
        free(p);
        return ;
    }

    //right child
    if (!p->left && p->right){
        //p is root
        if(!q){
            *t = p->right;
            free(p);
            return ;
        }

        if (side == 0)
            q->left = p->right;
        if (side)
            q->right = p->right;
        free(p);
        return ;
    }

    //both children
    if (p->left && p->right){
        node *r = NULL;//r is parent of s
        node *s = NULL;
        // go to p->left and then go to the rightmost node of left subtree
        s = p->left;
        while (s->right){
            r = s;
            s = s->right;
        }
        // s is now the right most node and r is parent of it.
        // make r->right = s->left
        //copy value of s into p

        if (!r){
            //s doesnt have right members.
            p->MIS = s->MIS;
            p->left = s->left;//s may have left subtree
            free(s);
            return ;
        }

        p->MIS = s->MIS;
        r->right = s->left;
        free(s);
        return ;
    }
}

int search(bst t, int d){
    if (!t)
        return 0;
    if (t->MIS == d){
        return 1;
    }
    if (d < t->MIS)
        search(t->left, d);
    else
        search(t->right,d);
    return ;
}

void postorder(bst t){
    if (!t)
        return ;
    stack s;
    inits(&s, 20);
    node *p = t;
    do{
        while (p){
            if (p->right)
                push(&s, *(p->right));
            push(&s, *p);
            p = p->left;
        }
        node nn = pop(&s);
        p = &(nn);

        if (p->right && peek(s).MIS == p->right->MIS){
            pop(&s);
            push(&s, *p);
            p = p->right;
        }
        else{
            printf("%d ",p->MIS);
	    printf("%s\n",p->name);
            p = NULL;
        }
    }while(!isEmptys(s));
}

void Display_Level(bst t, int i){
    //level reached and t is not NULL
    if (i == 0 && t){
        printf("%s:%d ", t->name, t->MIS);
        return ;
    }
    //t is null
    if (!t)
        return ;
    //counter for recursion
    int j = i-1;
    Display_Level(t->left, j);
    Display_Level(t->right, j);
    return ;
}

void destroyTree(bst *t){
    if (!*t)
        return ;
    node *p = *t;
    //left and right
    destroyTree(&p->left);
    destroyTree(&p->right);

    free(p);
    *t = NULL;
    return ;
}


//STACK FUNCTIONS

void inits(stack *s, int t) {
    s->size = t;
    s->arr = (node*)malloc(sizeof(node)* t);
    s->top = -1;
}

void push(stack *s, node p) {
    if(isFulls(*s)) {
        return;
    }
    s->arr[++s->top] = p;
    return;
}

node pop(stack *s){
    node nn;
    nn.MIS = INT_MIN;
    nn.left = nn.right = nn.parent = NULL;

    if(isEmptys(*s)){
        return nn;
    }
    return s->arr[s->top--];


}

node peek (stack s) {
     node n;
     n.MIS = INT_MIN;
     n.left = NULL;
     n.right = NULL;
     if(isEmptys(s)){
        return n;
     }
     return s.arr[s.top];
 }

int isFulls(stack s){
    if(s.top == s.size-1)
        return 1;
    else
        return 0;
}

int isEmptys(stack s){
    if(s.top == -1)
        return 1;
    else
        return 0;
}
