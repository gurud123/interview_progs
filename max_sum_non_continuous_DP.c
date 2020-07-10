/*
Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset.

For example, given an array  we have the following possible subsets:

Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8
Our maximum subset sum is .

Function Description

Complete the  function in the editor below. It should return an integer representing the maximum subset sum for the given array.

maxSubsetSum has the following parameter(s):

arr: an array of integers
Input Format

The first line contains an integer, .
The second line contains  space-separated integers .

Constraints

Output Format

Return the maximum sum described in the statement.

Sample Input 0

5
3 7 4 6 5
Sample Output 0
13
*/

int 
max(int x, int y)
{
    return (x>y?x:y);
}

// Complete the maxSubsetSum function below.
int maxSubsetSum(int arr_count, int* arr) {
    int i, inc, exc, tmp,tmp1;

    inc = exc = 0;
    for(i=0;i<arr_count;i++){
        if(i == 0){
            inc = arr[0];
            exc = 0;
            continue;
        }
        
        tmp = inc;
        tmp1 = exc;
        inc = exc + arr[i];
        exc = max(tmp, tmp1);
    }
    
    return (inc > exc ? inc : exc);
}
