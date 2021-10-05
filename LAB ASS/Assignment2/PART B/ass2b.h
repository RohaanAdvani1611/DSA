#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
}Node;

Node* newNode(int key);
void inorder(Node* root);
Node* constructBST(int postorder[], int start, int end);
