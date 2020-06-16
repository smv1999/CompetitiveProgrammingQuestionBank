/*
Find the number closest to n and divisible by m.

Q. Given two integers n and m. The problem is to find the number closest to n and divisible by m. If there are 
more than one such number, then output the one having maximum absolute value. If n is completely divisible by m, 
then output n only.

Sample Input/Output:
n = 13, m = 4
Output:
12

*/
#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    int n,m,res;
    scanf("%d %d",&n,&m);

    int p = n/m; 

    int first = m * p;

    int next = (n*m) > 0 ? (m*(p+1)) : (m*(p-1));

    if(abs(n-first)<abs(n-next))
    {
        printf("%d",first);
        return 0;
    }


    printf("%d",next);
    return 0;
}
