#include <stdio.h>
#include <stdlib.h>
#include "ass2b.h"

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

Node* constructBST(int postorder[], int start, int end) {
    // base case
    if (start > end) {
        return NULL;
    }
    //Root node is last key in Postorder Array
    Node *node = newNode(postorder[end]);
 
    //Find index of last element in Array smaller than Root
    int i;
    for (i = end; i >=start; i--) {
        if (postorder[i] < node->key) {
            break;
        }
    }
    //Construct Subtrees recursively right one first as we read elements from end to start 
    node->right = constructBST(postorder, i + 1, end - 1);
    node->left = constructBST(postorder, start, i);
    // return current node
    return node;
}