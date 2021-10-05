#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expTree.h"

int main(){
    ET t;
    char str[100];
    int ch;
    printf("Enter Infix Expression (in brackets): ");
    //fgets stores string pointed to by string
    fgets(str, 100, stdin); 
    initTree(&t, str);
    
    while (1){
        printf("\n\n1. Print Expression\n");
        printf("2. Compute Expression\n");
        printf("3. Exit Program\n");
        printf("Enter Choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                Traverse(t);
                break;
            case 2:
                printf("%d\n", compute(t, t)->key);
                break;
            case 3:
                exit(0);
            default:
                printf("\nWrong choice\n");
        }
        system("cls");
    }
}