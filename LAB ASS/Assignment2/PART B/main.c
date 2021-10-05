#include <stdio.h>
#include <stdlib.h>
#include "ass2b.h"
#include <limits.h>

int main() {
    int elem, size, op;
    int i = 0;
    char ch;
    printf("Enter size of postorder array: ");
    scanf("%d", &size);
    int postorder[size];

    for(i = 0; i < size; i++){
        printf("\nEnter element to add to post order: ");
        scanf("%d", &elem);
        postorder[i] = elem;
    }
    
    printf("\nPostorder Entered by user: ");
    for(i = 0; i < size; i++) 
        printf("%d ", postorder[i]);
    
    int n = sizeof(postorder)/sizeof(postorder[0]);
    
    Node* root = constructBST(postorder, 0, n-1);
    printf("\nThe Tree has been constructed");
    printf("\nInorder Traversal: ");
    inorder(root);
    return 0;
}
