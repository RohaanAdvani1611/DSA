#include <stdio.h>
#include <limits.h>
#include "heap.h"

int main() {
    heap h;
    int key;
    init_heap(&h, 20);
    
    key = delete_heap(&h);
    if (key == INT_MIN)
        printf("\nHeap is Empty\n");
    else{
        printf("\n%d is deleted\n", key);
        traverse_heap(h);
    }
    
    insert_heap(&h, 200);
    insert_heap(&h, 100);
    insert_heap(&h, 150);
    insert_heap(&h, 75);
    insert_heap(&h, 125);
    insert_heap(&h, 90);
    insert_heap(&h, 140);
    insert_heap(&h, 50);
    insert_heap(&h, 110);
    insert_heap(&h, 25);
    traverse_heap(h);
    
    key = delete_heap(&h);
    printf("\n%d is deleted\n", key);
    traverse_heap(h);
    
    return 0;
}
