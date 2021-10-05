#include <stdio.h>
#include <stdlib.h>
#include "ass2a.h"

int main() {
    bst t;
    int i, n, d;
    init_bst(&t, 100);
    printf("Enter no: of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Enter data to enter in BST: ");
        scanf("%d", &d);
        insert_bst(&t, d);
    }
    recursive_traverse(t, 0);
    int c = isComplete(t, 0, n);
    if(c == 1)
        printf("\nTree is complete");
    else
        printf("\nTree is not complete");
    return 0;
}
