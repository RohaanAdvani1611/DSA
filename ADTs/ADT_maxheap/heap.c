#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

void init_heap(heap *h, int s){
    h->size = s;
    h->rear = -1;
    h->A = (int*)malloc(sizeof(int)*s);
    return;
}

void insert_heap(heap *h, int k){
    int i = h->rear;
    int j = (i-1)/2;
    //Check if heap full
    if(h->rear == h->size-1)
        return;
    h->A[++h->rear] = k;
    while(i >= 0 && (h->A[i] > h->A[j])){
        swap(h, i, j);
        i = j;
        j = (i-1)/2;
    }
    return;
}

void swap(heap *h, int i, int j){
    int temp = h->A[i];
    h->A[i] = h->A[j];
    h->A[j] = temp;
}

void heapify(heap *h){
    //are there any elem remaining in tree or only 1 elem in tree
    if (h->rear <= 0)
        return;
    int i, l, r, m;
    i = 0;
    while(i <= h->rear){
        l = 2*i + 1;
        r = 2*i + 2;
        if(l > h->rear)//i is a leaf
            return;
        if(r > h->rear){//only 1 child of ith node
            //compare ith & lth node swap if required
            if(h->A[i] < h->A[l])
                swap(h, i, l);
            return;
        }
        //now we sure node i has both l & r 
        //find greater of lth & rth nodes
        if(h->A[l] > h->A[r])
            m = l;
        else
            m = r;
        swap(h, i, m);
        i = m;
    }
    return;
}

int delete_heap(heap *h){
    int e = INT_MIN;
    // heap is empty
    if(h->rear == -1)
        return e;
    e = h->A[0];
    //copy last elem to 0th loc 
    h->A[0] = h->A[h->rear];
    //heap size to reduce
    h->rear--;
    //reconvert to heap
    heapify(h);
    return e;
}

void traverse_heap(heap h){
    for (int i = 0; i <= h.rear; i++)
        printf("%d ", h.A[i]);
    return;
}