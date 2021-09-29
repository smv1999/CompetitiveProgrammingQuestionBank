/* 
Sample Input 1

5
Sample Output 1

1
Sample Input 2

13
Sample Output 2

2


Input Format

A single integer,n .

Output Format

Print a single base-10 integer that denotes the maximum number of consecutive 1's in the binary representation of n.  */


#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
   
    int rem = 0;
    int curr = 0;
    int max = 0;


    while(n > 0) {
        rem = n % 2;
        if(rem == 1) {
            curr++;
            if(curr >= max) {
                max = curr;
            }
        } else {
            curr = 0;
        }
        n = n / 2;
    }

    printf("%d\n", max);

    return 0;
}
