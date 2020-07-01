#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    // for first half
    for(int i=n;i>=2;i-=2,printf("\n"))
    {
        printf("%*s",(n-i)/2,"");
        for(int j=1;j<=i;j++)
        {
            printf("*");
        }
    }
    // for second half
     for(int i=2;i<=n;i+=2,printf("\n"))
    {
        printf("%*s",(n-i)/2,"");
        for(int j=1;j<=i;j++)
        {
            printf("*");
        }
    }
    return 0;
}
