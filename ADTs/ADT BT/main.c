#include <stdio.h>

int main() {
    bt t;
	init_bt(&t);
	
	insert_bt(&t, 45);
	insert_bt(&t, 50);
	insert_bt(&t, 35);
	insert_bt(&t, 30);
	insert_bt(&t, 55);
	insert_bt(&t, 40);
	
	printf("Inorder Traversal: ");
	inorder_bt(t);

    return 0;
}
