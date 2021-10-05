#include <stdio.h>

typedef struct heap{
    int *A;
    int rear, size;
} heap;

void init_heap(heap *h, int s);
void insert_heap(heap *h, int k);
int delete_heap(heap *h);
void traverse_heap(heap h);
void swap(heap *h, int i, int j);
void heapify(heap *h);