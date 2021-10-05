#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    FILE *fp1,*fp2,*fpSUM,*fpDIFF;


    fp1 = fopen("Matrix1.txt","r");
    fp2 = fopen("Matrix2.txt","r");
    fpSUM = fopen("MatrixSum.txt","w");
    fpDIFF = fopen("MatrixDiff.txt","w");
    if (fp1 == NULL || fp2 == NULL || fpSUM == NULL|| fpDIFF == NULL){
        printf("The file could not be opened .");
        exit(1);
    }

    int p1[MROW][MCOL];
    int p2[MROW][MCOL];

    get_array_from_txt(&fp1,p1);
    get_array_from_txt(&fp2,p2);

    sparse l1,l2,resultsum,resultdiff;

    get_list_from_matrix(p1,&l1,row,col);
    get_list_from_matrix(p2,&l2,row,col);


    addition(&resultsum,l1,l2);
    subtract(&resultdiff,l1,l2);

    print_sparse_into_txt(&fpSUM,resultsum);
    print_sparse_into_txt(&fpDIFF,resultdiff);

    fclose(fp1);
    fclose(fp2);
    fclose(fpSUM);
}
