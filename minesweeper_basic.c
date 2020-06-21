/*
This program determines the minesweeper functionality.
Given the location of bombs index in the matrix, the programming determines the 
index computed by the Minesweeper Game
*/

#include <stdio.h>
#include "malloc.h"

int **
mines(int row, int col)
{
    int i,j,p,q,bombs=0;
    int **m;
    m = malloc(sizeof(int)*col);
    for(i=0;i<row;i++){
        m[i]=malloc(sizeof(int)*row);
    }
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            m[i][j] = 0;
        }
    }
    
    p=0;q=0;
    m[p][q] = -1;
    p=0;q=1;
    m[p][q] = -1;
    
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            
            if(m[i][j] == -1) {            
            if(((i-1) >= 0) && ((j-1) >= 0)) {
                if(m[i-1][j-1] != -1)
                    m[i-1][j-1]++;
                                
                    if(m[i-1][j] != -1)
                        m[i-1][j]++;
                                
                    if(((j+1) < col) && (m[i-1][j+1] != -1))
                        m[i-1][j+1]++;
                            
                    if(m[i-1][j] != -1)
                        m[i-1][j]++;
            }

            if(( (i+1) < row) && ((j+1) < col)) {
                if(m[i+1][j+1] != -1)
                    m[i+1][j+1]++;
                            
                if(m[i+1][j] != -1)
                    m[i+1][j]++;
                                
                if(((j-1) >= 0) && (m[i+1][j-1] != -1)){
                    if(m[i+1][j-1] != -1)
                        m[i+1][j-1]++;
                }
                            
                if(m[i][j+1] != -1)
                    m[i][j+1]++;
            }
                
            }
        }    
    }
    
    
    return m;    
}

int main()
{
    int **m,i,j;
    int a[2][2]={{0,0},{0,1}};
    m = mines(3,3);
    
    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++){
            printf("%d  ",m[i][j]);
        }
    }
    return 0;
}
