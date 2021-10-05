#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "bstree.h"

int main() {
    int dep, cnode, cleaves, full, comp;
	bst t;
	init_bst(&t);
	
	insert_bst(&t, 45);
	insert_bst(&t, 50);
	insert_bst(&t, 35);
	insert_bst(&t, 30);
	insert_bst(&t, 55);
	insert_bst(&t, 40);
	
	printf("Inorder: ");
	inorder_bst(t);
	printf("\nNon Rec Inorder: ");
	inorder_nonrecursive(t);
	printf("\nPre order: ");
	preorder_bst(t);
	printf("\nPost order: ");
	postorder_bst(t);
	printf("\nLevel order: ");
	//level_order(t);
	
	dep = depth(t);
	printf("\nDepth of tree = %d", dep);
	cnode = count_node(t);
	printf("\nNo: of nodes in tree = %d", cnode);
	cleaves = count_leaves(t);
	printf("\nNo: of leaves in tree = %d", cleaves);
	
	full = isFull_bst(t);
	if (full == 1)
	    printf("\nTree is full");
	else
	    printf("\nTree is not full");
	    
	comp = isComplete_bst(t);
	if (comp == 1)
	    printf("\nTree is complete");
	else
	    printf("\nTree is not complete");
	    
	if(search(t, 50))
	    printf("\nFOUND");
	else
	    printf("\nNOT FOUND");
	return 0;
}