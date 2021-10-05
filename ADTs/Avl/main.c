#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main() {
    AVL t;
    int option;
    char month[len];
    initAVL(&t);
    while(1){
        printf("\n1. Insert Month into Avl tree");
        printf("\n2. Display elements in Avl tree");
        printf("\n3. Remove element from Avl tree");
        printf("\n4. Exit Program");
        printf("\nEnter choice : ");
        scanf("%d", &option);
        switch(option){
            case 1 :
                printf("\nEnter the month to be inserted: ");
                scanf("%s", month);
                insertNode(&t, month);
                break;
            case 2 :
                printf("\n");
                traverse(t);
                printf("\n");
                break;
            case 3 :
                printf("\nEnter the month to be removed : ");
                scanf("%s", month);
                removeNode(&t, month);
                break;
            case 4 :
                destroyTree(&t);
                printf("\nThe tree has been destroyed");
                exit(0);
                break;
            default :
                printf("\nWrong choice");
                break;
        }
        printf("\n");
    }
    return 0;
}
