#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<conio.h>
#include "heap.h"

void init_heap(heap *h, int s){
    h->rear = -1;
    h->size = s;
    h->A = (int*)malloc(sizeof(int)*s);
}

void traverse_heap(heap h){
    for(int i = 0; i <= h.rear; i++)
        printf("%d ", h.A[i]);
}

void insert_heap(heap *h, int d){
    if(h->rear == h->size - 1)
        return;
    h->A[++h->rear] = d;
    int i = h->rear;
    int j = (i-1)/2;
    while(i >= 0 && (h->A[i] > h->A[j])){
        swap(h, i, j);
        i = j;
        j = (i-1)/2;
    }
}

int remov(heap *h){
    if(h->rear == -1)
        return INT_MIN;
    int res = h->A[0];
    swap(h, h->rear, 0);
    h->rear--;
    heapify(h);
    return res;
}

void swap(heap *h, int i, int j){
    int temp = h->A[i];
    h->A[i] = h->A[j];
    h->A[j] = temp;
}

void heapify(heap *h){
    int i = 0, m;
    int l, r;
    while(i <= h->rear){
        l = 2*i + 1;
        r = 2*i + 2;
        if (l > h->rear)
            return;
        else if(r > h->rear){
            if(h->A[l] > h->A[i])
                swap(h, l, i);
            return;
        }
        m = (h->A[l] > h->A[r]) ? l : r;
        if(h->A[m] > h->A[i])
            swap(h, m, i);
        i = m;
    }
}

void heap_Sort(heap *h){
    int arr[h->size];
    for (int i =0;i < h->size; i++)
        arr[i] = remov(h);
    printf("Sorted Heap : ");
    for (int i = h->size - 1;i >= 0; i--)
        printf("%d ", arr[i]);
}