#include<stdio.h>
#include"avl.h"

int main(){
    AVLTree t;
    init_AVL(&t);

    insert_AVL(&t, 13);
    insert_AVL(&t, 10);
    insert_AVL(&t, 15);
    insert_AVL(&t, 16);
    insert_AVL(&t, 5);
    insert_AVL(&t, 11);
    insert_AVL(&t, 4);
    insert_AVL(&t, 8);
    insert_AVL(&t, 3);

    printf("\n after deletion of a node 8 \n");
    remoov_AVL(&t,8);
    inorder_AVL(t);
    printf("\n after deletion of a node 11\n");
    remoov_AVL(&t,11);
    inorder_AVL(t);
    printf("\n after deletion of a node 4\n");
    remoov_AVL(&t,4);
    inorder_AVL(t);
    printf("\n after deletion of a node 13\n");
    remoov_AVL(&t,13);
    inorder_AVL(t);


    return 0;
}



