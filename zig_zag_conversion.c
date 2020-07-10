/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/
#include "stdio.h"
#include "malloc.h"
#include "string.h"


char * convert(char * s, int numRows){
    char *p[numRows];
    char *ptr = NULL;
    int len=0;
    int i,j,k,reverse;
    char *target = NULL;
    
    len = strlen(s);
    
    int index[numRows];
    memset(index,0,sizeof(index));
    
    if((numRows == 0) || (numRows == 1) || (len == 1)){
        return s;
    }
    
    if(numRows >= len){
        return s;
    }
    
    for(i = 0; i<numRows;i++){
        p[i]=malloc(sizeof(char)*((len/2)+2));
        if(p[i] == NULL)
            return NULL;
    }
    
    i=0;j=0;reverse=0;
    while(s[i] != '\0')
    {
        ptr = p[j];
        ptr[index[j]] = s[i];
        i++;
        index[j]++;
        if(j == (numRows-1)){
            reverse=1;
            j--;
            continue;
        }
        if((reverse == 1) && (j == 0)){
            reverse = 0;
            j++;
            continue;
        }
        if(reverse == 1)
            j--;
        else
            j++;
    }
    
    target = malloc(sizeof(char)*(len+1));
    k=0;
    for(i=0;i<numRows;i++){
        ptr=p[i];
        j=0;
        
        while(j < index[i]){
            target[k++]=ptr[j++];
        }
        
        if(p[i]){
            free(p[i]);
            p[i]=NULL;
        }
        
    }
    target[k]='\0';
    return target;
}

int main()
{
    char *p[2]={};
    char *ptr = NULL;
    char s[]="PAYPALISHIRING";
    int i=0,j=0;
    ptr = convert(s,10);
    printf("\nstr returned is %s",ptr);
    return 0;
}
