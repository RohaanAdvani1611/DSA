#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(){
    bst t;
    int choice;
    int mis;
    char name[25];
    initBST(&t);
    while(1){
        printf("\n1.Insert Node in BST");
        printf("\n2.Remove Node in BST");
        printf("\n3.Search Node in BST");
        printf("\n4.Iterative Postorder Traversal");
        printf("\n5.Display i-th Level Nodes");
        printf("\n6.Destroy Tree");
        printf("\n7.Exit Program");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("\nEnter MIS number : ");
                scanf("%d", &mis);
                printf("\nEnter Name of the student : ");
                scanf("%s",name);
                insertNode(&t, mis, name);
                break;
            case 2:
                printf("\nEnter MIS to be removed: ");
                scanf("%d", &mis);
                removeNode(&t, mis);
                break;
            case 3:
                printf("\nEnter MIS to be searched: ");
                scanf("%d", &mis);
                int x = search(t, mis);
                if( x == 1)
                    printf("\nNode Found\n");
                else
                    printf("\nNode not Found\n");
                break;
            case 4:
                printf("\n");
                postorder(t);
                printf("\n");
                break;
            case 5:
                printf("\nEnter level you want to display: ");
                int y;
                scanf("%d", &y);
                printf("\n");
                Display_Level(t, y);
                printf("\n");
                break;
            case 6:
                destroyTree(&t);
                printf("Tree Destroyed");
                break;
            case 7:
                    exit(0);
            default:
                    printf("\nWrong option chosen");
                    break;
        }
    }
    return 0;
}