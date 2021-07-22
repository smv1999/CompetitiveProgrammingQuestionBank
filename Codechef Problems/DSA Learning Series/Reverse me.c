/* You are given a list of N integers and you need to reverse it and print the reversed list in a new line.

Input:
First-line will contain the number N.
Second line will contain N space-separated integers.
Output:
Print the reversed list in a single line.

Constraints
1≤N,Ai≤105
Sample Input 1:
4
1 3 2 4
Sample Output 1:
4 2 3 1
Sample Input 2:
2
9 8
Sample Output 2:
8 9
EXPLANATION:
In the first example, the reverse of the [1,3,2,4] is [4,2,3,1].
In the second example, the reverse of [9,8] is [8,9]. */

#include <stdio.h>

int main(void) {
	
	int n;
	scanf("%d",&n);
	int a[n];
	
	for(int i=1;i<=n;i++)
	{
	    scanf("%d ",&a[i]);
	    
	}
	
		for(int i=n;i>=1;i--)
	{
	    printf("%d ",a[i]);
	    
	}
	return 0;
}
