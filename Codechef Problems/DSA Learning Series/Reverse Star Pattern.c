/* You're given a number N. Print the first N lines of the below-given pattern.

    *
   **
  ***
 ****
*****
Input:
First-line will contain the number N.
Output:
Print the first N lines of the given pattern.

Constraints
1≤N≤200
Sample Input 1:
4
Sample Output 1:
   *
  **
 ***
****
Sample Input 2:
2
Sample Output 2:
 *
**
EXPLANATION:
In the first example, we'll print the first 4 lines of the given pattern.
In the second example, we'll print the first 2 lines of the given pattern */


#include <stdio.h>

int main(void) {
	
	int t;
	scanf("%d",&t);

        for(int i=1;i<=t;i++)
        {
            for(int j=t;j>i;j--)
            printf(" ");
            for(int k=1;k<=i;k++)
            printf("*");
            printf("\n");
        }
        
	
	return 0;
}
