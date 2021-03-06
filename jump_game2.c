/* Given an array of non-negative integers, you are initially positioned at the first index of the array.
  * Each element in the array represents your maximum jump length at that position.
  * Your goal is to reach the last index in the minimum number of jumps.
  * Example:
  * Input: [2,3,1,1,4]
  * Output: 2
  * Explanation: The minimum number of jumps to reach the last index is 2.
  *   Jump 1 step from index 0 to 1, then 3 steps to the last index.
  * Note:
  * You can assume that you can always reach the last index.
  */
#include "stdio.h"



int jump(int* nums, int numsSize){
    int curr_best = 0,prev_best,i,next_best;
    int jump=0,next_index=0;
    i=0;
    curr_best = prev_best = next_best = 0;
    int jump_array[numsSize],jump_index=0;
    while(i < (numsSize-1))
    {
        if(curr_best == 0){
            /*could be 2 possibilities
             * 1. First index 
             * - Just initialize the number and continue.    
             * 2. Or we have run out of fuel
             * - assign the available next best, subtract the value based on 
               - index count
             */
            if(next_best == 0){
                curr_best = nums[i];
                next_best = nums[i];
                next_index = i;
                jump_array[jump_index++]=nums[i];
                //jump_index++;
                printf("@line:%d jump_index is %d",__LINE__,jump_index);
            } else {
                /* Check whether nums[i] is greater than stored next bext
                */
                if(nums[i] > (next_best-(i-next_index))){
                    curr_best = nums[i];
                    next_best = curr_best;
                    next_index = i;
                    i++;
                    curr_best--;
                    jump_array[jump_index++]=nums[i];
                    //jump_index++;
                    printf("@line:%d jump_index is %d",__LINE__,jump_index);
                    continue;
                } else {
                    curr_best = next_best-(i-next_index);
                    jump_array[jump_index++]=next_best;
                    curr_best--;
                    i++;
                    
                    continue;
                }
            }
        }
            
        if(curr_best < nums[i]){
            if((next_best - (i-next_index)) < nums[i]){
                next_best = nums[i];
                next_index = i;
            }
            
        }
        i++;
        curr_best--;
            
        
    }
    return jump_index;
}

int main()
{
    int n[]={4,0,6,2,3,7,2,4,0},ans;
    int n_size=sizeof(n)/sizeof(n[0]);
    ans = jump(n, n_size);
    printf("\nNo of jumps = %d",ans);
    return 0;
}
