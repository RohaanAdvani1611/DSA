int insertion(int a[]) {
    int i, j, c;
    for(i = 1; i < size; i++) {
        j = i;
        while(j > 0 && a[j - 1] > a[j]) {
            c = a[j];
            a[j] = a[j - 1];
            a[j - 1] = c;
            j--;
        }
    }
    printf("\nSorted array\n");
    for(i = 0; i < size; i++) 
        printf("%d ", a[i]);
    
    return 0;
}

int bubble(int a[]) {
    int i, j, c;
    for(i = 0; i < size; i++) {
        for(j = i; j < size; j++) {
            if(a[i] > a[j]) {
                c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
        }
    }
    printf("\nSorted array\n");
    for(i = 0; i < size; i++) 
        printf("%d ", a[i]);
    
    return 0;
}

int selection(int a[]) {
    int i, j, c;
    for(i = 0; i < size; i++) {
        for(j = i; j < size; j++) {
            if(a[i] > a[j]) {
                swap(&a[i], &a[j]);
            }
        }
    }
    printf("\nSorted array\n");
    for(i = 0; i < size; i++) 
        printf("%d ", a[i]);
    
    return 0;
}

int swap(int *a, int *b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
