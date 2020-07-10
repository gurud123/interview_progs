/*
Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  All the children sit in a line and each of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to minimize the total number of candies she must buy.

For example, assume her students' ratings are [4, 6, 4, 5, 6, 2]. She gives the students candy in the following minimal amounts: [1, 2, 1, 2, 3, 1]. She must buy a minimum of 10 candies.

Function Description

Complete the candies function in the editor below. It must return the minimum number of candies Alice must buy.

candies has the following parameter(s):

n: an integer, the number of children in the class
arr: an array of integers representing the ratings of each student
Input Format

The first line contains an integer, , the size of .
Each of the next  lines contains an integer  indicating the rating of the student at position .

Constraints

Output Format

Output a single line containing the minimum number of candies Alice must buy.

Sample Input 0

3
1
2
2
Sample Output 0

4
Explanation 0

Here 1, 2, 2 is the rating. Note that when two children have equal rating, they are allowed to have different number of candies. Hence optimal distribution will be 1, 2, 1.

Sample Input 1

10
2
4
2
6
1
7
8
9
2
1
Sample Output 1

19
Explanation 1

Optimal distribution will be 

Sample Input 2

8
2
4
3
5
2
6
4
5
Sample Output 2

12
Explanation 2

Optimal distribution will be .12121212
*/

#define max(x,y) ((x>y)?x:y)

// Complete the candies function below.
long candies(int n, int arr_count, int* arr) {
 int i;
    int rt[arr_count],lt[arr_count];
    long val = 0;
    
    for(i=0;i<arr_count;i++){
        lt[i]=rt[i]=1;  //Every child should atleast get 1 candy
    }

    for(i=1;i<arr_count;i++){
        if(arr[i] > arr[i-1]){
            lt[i] = lt[i-1] + 1;
        }
    }
    
    for(i=(arr_count-2); i > -1; i--){
        if(arr[i] > arr[i+1]){
            rt[i] = rt[i+1]+1;
        }
    }
    
    for(i=0;i<arr_count;i++){
        val += max(lt[i], rt[i]);
    }
    
    return val;
}

