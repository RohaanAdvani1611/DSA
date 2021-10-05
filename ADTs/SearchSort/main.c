#include<stdio.h>
#define size 10
#include "search.h"
#include "sorting.h"

int main() {
    int op, i, a[size], ans;
    for(i = 0; i < size; i++) 
        a[i] = rand(size);
    
    printf("Random array\n");
    for(i = 0; i < size; i++) 
        printf("%d ", a[i]);
    
    do {
        printf("\n1. Linear search");
        printf("\n2. Binary search");
        printf("\n3. Insertion sort");
        printf("\n4. Bubble sort");
        printf("\n5. Selection sort");
        printf("\nEnter your choice : ");
        scanf("%d", &op);
        switch(op) {
            case 1 :
                linear(a);
                break;
            case 2 :
                binary(a);
                break;
            case 3 :
                insertion(a);
                break;
            case 4 :
                bubble(a);
                break;
            case 5 :
                selection(a);
                break;
            default :
                printf("Wrong option chosen");
                
        }
        printf("\nPress 1 to continue and 0 to end program : ");
        scanf("%d", &ans);
    }while(ans == 1);
    return 0;
}
