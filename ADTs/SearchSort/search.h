int linear(int a[]) {
    int el, flag = -1, i = 0;
    printf("\nEnter element for searched : ");
    scanf("%d", &el);
    for(i = 0; i < size; i++) {
        if(a[i] == el) {
            printf("\nElement found at location %d", (i + 1));
            flag = 0;
        }
    }
    if(flag == -1) 
        printf("\nElement not found");
    
    return 0;
}

int binary(int a[]) {
    int i, c, j, m;
    for(i = 0; i < size; i++) {
        for(j = i; j < size; j++) {
            if(a[i] > a[j]) {
                c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
        }
    }
    i = 0;
    j = size - 1;
    m = (i + j)/2;
    printf("\nEnter element for search : ");
    scanf("%d", &c);
    while(i <= j) {
        if(a[m] < c) 
            i = m + 1;
        
        else if(a[m] == c) {
            printf("\nElement found at location %d", (m + 1));
            break;
        }
        else 
            j = m - 1;
        
        m = (i + j)/2;
    }
    if(i > j) 
        printf("\nElement not found");
    
    return 0;
}