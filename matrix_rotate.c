/*
 * This program rotates the given square matrix by 90 degrees.
  Example
/*
1 2 3 	  3 6 9
4 5 6  ==>	  2 5 8
7 8 9		  1 4 7

1 1 1 1 1		1 2 3 4 5
2 2 2 2 2		1 2 3 4 5
3 3 3 3 3 ==>	1 2 3 4 5
4 4 4 4 4		1 2 3 4 5
5 5 5 5 5		1 2 3 4 5
*/

#include <stdio.h>

int row=5; 
int col=5;
display(int a[row][col])
{
    int i,j;
    for(i = 0; i<row;i++){
        printf("\n");
        for(j=0;j<col;j++) {
            printf("%d  ",a[i][j]);
        }
    }
}
void
rotate(int a[row][col])
{
    int i,j,k,tmp;
    
    i=0;
    for(j=0;j<col;j++){
        if(i == j){
            continue;
        }
        tmp = a[j][i];
        a[j][i] = a[i][j];
        a[i][j] = tmp;
    }
    printf("\nAfter first stage");
    display(a);
    
    if((col -2) > 1){
        i = 1;
        for(j = 1; j<(col -1); j++){
            if(i == j){
                continue;
            }
            tmp = a[j][i];
            a[j][i] = a[i][j];
            a[i][j] = tmp;
        }
    }
    printf("\nAfter inner 1st stage");
    display(a);
    printf("\n");
    
    j=col-1;
    for(i=1;i<row;i++){
        if(i == j)
            continue;
        tmp = a[j][i];
        a[j][i] = a[i][j];
        a[i][j] = tmp;        
    }
    printf("\nAfter 2nd stage");
    display(a);
    printf("\n");
    
    if((col -2) > 1){
        j = col-2;
        for(i = 2; i<(row -1); i++){
            if(i == j){
                continue;
            }
            tmp = a[j][i];
            a[j][i] = a[i][j];
            a[i][j] = tmp;
        }
    }
    printf("\nAfter inner 2nd stage");
    display(a);
    printf("\n");
    
    /* Now swap the rows */
    for(i=0;i<row/2;i++){
        k=row-i-1;
        for(j=0;j<col;j++){
            tmp = a[i][j];
            a[i][j] = a[k][j];
            a[k][j] = tmp;
        }
    }
    for(i = 0; i<row;i++){
        printf("\n");
        for(j=0;j<col;j++) {
            printf("%d  ",a[i][j]);
        }
    }
    
    return;
}
int main()
{
    //int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int a[5][5] =   {{1,1,1,1,1},
                     {2,2,2,2,2},
                     {3,3,3,3,3},
                     {4,4,4,4,4},
                     {5,5,5,5,5}};
                        
    int i,j;
    printf("Input matrix");
    display(a);
    rotate(a);
    

    return 0;
}
