/*
Logic Pyramid
-------------

input 3
output
        00006
     00028 00066
  00120 00190 00276      

The input consists of a number n, and the output is a logic pyramid of n rows.
*/
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n,a=2,b=3;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        printf("%*s",(n-i)*3,"");
        for(int j=1;j<=i;j++)
        {
            printf("%05d ",a*b);
            a = a + 2;
            b = b + 4;
        }
        printf("\n");
    }
    
    return 0;
}
