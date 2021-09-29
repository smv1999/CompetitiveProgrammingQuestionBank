/* 
Sample Input

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0
Sample Output

19 

Input Format

There are 6 lines of input, where each line contains 6 space-separated integers that describe the 2D Array A.

Output Format

Print the maximum hourglass sum in A.  */

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N = 6;
    int arr[N][N];

    for(int arr1 = 0; arr1 < N; arr1++) {
       for(int arr2 = 0; arr2 < N; arr2++) {
          scanf("%d",&arr[arr1][arr2]);
       }
    }

    int max = -500;
    int curr = 0;
    for(int arr1 = 0; arr1 < N - 2; arr1++) {
        for(int arr2= 0; arr2 < N - 2; arr2++) {
            int a = arr[arr1][arr2];
            int b = arr[arr1][arr2 + 1];
            int c = arr[arr1][arr2 + 2];
            int d = arr[arr1 + 1][arr2 + 1];
            int e = arr[arr1 + 2][arr2];
            int f = arr[arr1 + 2][arr2 + 1];
            int g = arr[arr1+ 2][arr2 + 2];

            curr = a + b + c + d + e + f + g;
            if(curr > max) {
                max = curr;
            }
        }
    }

    printf("%d", max);

    return 0;
}
