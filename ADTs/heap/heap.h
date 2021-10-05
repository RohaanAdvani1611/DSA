typedef struct{
    int *A;
    int rear;
    int size;
}heap;

void init_heap(heap *h, int s);
void insert_heap(heap *h, int d);
void traverse_heap(heap h);
int remov(heap *h);
void heap_Sort(heap *h);
void heapify(heap *h);
void swap(heap *h, int i, int j);
