#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<conio.h>
#include "heap.h"

int main(){
    int key;
    heap h;
    FILE *f;
    f = fopen("unsorted.txt", "r");
    if(!f) {
        printf("File can't open");
        exit(0);
    }
    init_heap(&h, 8);
    for (int i = 0; i< 8; i++){
        fscanf(f, "%d ", &key);
        insert_heap(&h, key);
    }
    heap_Sort(&h);
    fclose(f);
}
