#include<stdlib.h>
#include"avl.h"
#include<stdio.h>
#include<math.h>

void init_AVL(AVLTree *t){
    *t = NULL;
    return ;
}

void LLrotate(AVLTree *t,node *i){
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

    if(b)
        b->parent = i;

    i->bf = i->bf - a->bf - 1;
    a->bf = 0 ;
    return;


}
void LRrotate(AVLTree *t,node *i){
    //node *p = i->parent;
    node *a = i->left;
    node *b = a->right;
    b->left = a;
    a->right  = NULL;
    a->parent = b;
    b->parent = i;
    i->left = b;
    b->bf = a->bf;
    a->bf++;

    LLrotate(t,i);
    return;

}
void RRrotate(AVLTree *t,node *i){}
void RLrotate(AVLTree *t,node *i){}


void insert_AVL(AVLTree *t, int d){
    node *nn = (node*)malloc(sizeof(node));
    if(!nn)
        return;
    nn->key = d;
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
        // < , > , == ( p->key and d)
        q = p;
        if(p->key == d){
            free(nn);
            return;
        }
        if(d < p->key){
            //p->bf++;
            p = p->left;
        }
        else{
           //p->bf--;
           p = p->right;
        }
    }
    if(d < q->key)
        q->left  = nn;
    else
        q->right = nn;

    nn->parent = q;


    //setting of bf form nn to root to be  done now

    p = nn->parent;
    q = nn;
    node *i = NULL;
    while(p){
        if(q->key < p->key)
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
        printf("\nImbalance at: %d - %d\n", i->key, i->bf);
        if(i->bf >= 2){
            if(d < i->left->key){
                    printf("LLrotate required\n");
                    //inorder_AVL(*t);

                    LLrotate(t,i);
            }
            else{
                    printf("\nLRrotate is required\n");
                    LRrotate(t,i);
            }
        }
        else {
            if(d < i->right->key){
                printf("RLrotate(t,i)");
                RLrotate(t,i);
            }

            else{
                printf("RRrotate(t,i)");
                RRrotate(t,i);
            }
        }
    }
    return ;
}

void inorder_AVL(AVLTree t){
    if(!t)
        return;
    inorder_AVL(t->left);
    printf("%d - %d -",t->key,t->bf);
    if(t->parent)
        printf("%d\n",t->parent->key);
    else
        printf("NULL\n");
    inorder_AVL(t->right);
    return ;
}

//Adjust the balance factor from p to root


node* search_AVL(AVLTree t, int d){
    node *p = t;
    //empty tree
    if(!p) return p;
    while(p){
        if(d == p->key)
            return p;
        if(d < p->key)
            p = p->left;
        else
            p = p->right;
    }
    return p;

}
int height_AVL(AVLTree t){
    if(!t)
        return -1;
    int l,r;
    l = height_AVL(t->left);
    r = height_AVL(t->right);
    if(l > r)
        return ++l;
    else
        return ++r;
}


void adjust_bf(AVLTree *t,node *q){
    node *p = q;
    //p = q->parent;

    while(p){
            if(abs(q->bf) != 1){
            printf("\n%d\n", p->key);
            getch();
            if(p->bf == 2 && p->left->bf >=0){
                printf("\n LL rotation\n");
                LLrotate(t,p);
            }
            else if(p->bf == 2 && p->left->bf < 0){
                printf("\n LR rotation\n");
                LLrotate(t,p);
            }
            else if(p->bf == -2 && p->right->bf < 0)
                printf("\n RR rotation\n");
            else if(p->bf == -2 && p->right->bf >= 0)
                printf("\n RL rotation\n");
            else {
                    if(p->left == q)
                            p->bf--;
                    else
                        p->bf++;
                    q = p;


                }
                p = p->parent;
            }
            else
                return;
    }

    //inorder_AVL(*t);
    return;

}


void remoov_AVL( AVLTree *t, int d){
    if(!t) //tree is empty
        return;
    node *p, *q = NULL;
    // set the pointer p to the root
    p = *t;
    int side;
    // searching for d in the tree
    while(p){
        if(d == p->key)
            break;
        q = p;
        if(d < p->key){
            p = p->left;
            side = 0;
        }
        else{
            p = p->right;
            side = 1;
        }
    }

    // p is NULL means d not found
    if(!p)
        return;


    // p is not NULL means node is found

    // is p a leaf?
    if(!p->left && !p->right){
        if(!q){ // only one node in the tree
            *t = NULL;
            free(p);
            return;
        }
        if(side){
            q->right = NULL;
            q->bf++;
        }
        else{
            q->left = NULL;
            q->bf--;
        }
        adjust_bf(t,q);
        free(p);
        return;

    }

    // one child?
    //left child
    if(p->left && !p->right){

        if(!q){ // means p is a root node with only left child
            *t = p->left;
            free(p);
            return ;
        }
        if(side == 0){ // p is the left child of q
            q->left = p->left;
            p->left->parent = q;
            q->bf--;
        }
        else {      // p is the right child of q
            q->right = p->left;
            p->right->parent = q;
            q->bf--;
        }
        adjust_bf(t,q);
        free(p);

    }
    // only right child
    if(!p->left && p->right){
        if(!q){ // means p is a root node with only left child
            *t = p->right;
            free(p);
            return ;
        }
        if(side == 0) // p is the left child of q
            q->left = p->right;
        else         // p is the right child of q
            q->right = p->right;
        free(p);

    }


    // two children node

    if(p->right && p->left){ // p is a node with both children
      node *r = NULL, *s = NULL;  //r as parent of s  like q was parent of p
      // go to the left then to the rightmost node
      s = p->left;
      while(s->right){
        r = s;
        s = s->right;
      }
      //r is null
      //copy s value to p
      // p->left as null and free s

      if(!r){
        p->key = s->key;
        p->left = s->left;
        s->left->parent = p;
        p->bf--;
        free(s);

        return;
      }
      //copy key of node s to p
      //make right of r as s->left
      // free s
      r->bf++;
      p->key = s->key;
      r->right = s->left;
      free(s);
      return;
    }

    return ;
}