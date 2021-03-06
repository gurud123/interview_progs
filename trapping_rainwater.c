/*
  * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
  * compute how much water it is able to trap after raining.
  *
  * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
  * In this case, 6 units of rain water (blue section) are being trapped. 
  * Example:
  *  Input: [0,1,0,2,1,0,1,3,2,1,2,1]
  * Output: 6
  */

#include "stdio.h"
#include "malloc.h"

int max(int x,int y)
{
    return (x>y?x:y);
}

int min(int x, int y)
{
    return (x>y?y:x);
}

int trap(int* height, int heightSize){
    int i,j,ht_max_left,ht_max_right,total;
    int *left_ht, *right_ht;
    left_ht = right_ht = NULL;
    
    left_ht = malloc(sizeof(int)*heightSize);
    right_ht = malloc(sizeof(int)*heightSize);
    if((left_ht == NULL) || (right_ht == NULL))
        return 0;
    
    if(heightSize < 2)
        return 0;
    ht_max_left = ht_max_right = total = 0;
    for(i=heightSize-1; i>(-1) ; i--){
        right_ht[i] = max(ht_max_right,height[i]);
        if(right_ht[i] > ht_max_right){
            ht_max_right = right_ht[i];
        }
    }
    
    
    for(i=0;i<heightSize;i++){
        left_ht[i] = max(ht_max_left,height[i]);
        if(left_ht[i] > ht_max_left){
            ht_max_left = left_ht[i];
        }
        //printf("\nindex:%d left_ht:%d right_ht:%d curr_ht:%d",i,left_ht[i],right_ht[i],height[i]);

        total += min(left_ht[i],right_ht[i])-height[i]; 
    }
    return total;
}

int main()
{
    int n,ans;
    int h[]={0,1,0,2,1,0,1,3,2,1,2,1};
    n = sizeof(h)/sizeof(h[0]);
    ans = trap(h,n);
    printf("\nans returned is %d",ans);
    return 0;
}
