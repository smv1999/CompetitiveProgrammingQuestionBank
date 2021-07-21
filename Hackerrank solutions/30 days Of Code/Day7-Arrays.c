/* Sample Input

4
1 4 3 2
Sample Output

2 3 4 1  

Print the elements of array A in reverse order as a single line of space-separated numbers. */

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
    
    int n; int temp;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
    scanf("%d",&a[i]);}
    
    for(int i=n-1; i>=0;i--)
    printf("%d ",a[i]);
    return 0;
}
