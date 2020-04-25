/*
Christmas Tree Pattern

input 3
output 
        *
       ***
      *****
     *******
       ***
      *****
        *
        * 

We divide the problem into 3 parts: 
1. Full triangle
2. Partial Triangle
3. Stand
*/
#include<stdio.h>

void fulltriangle(int row)
{
    for(int i=1;i<=row;i++)
    {
        printf("%*s",row-i,"");
        for(int j=1;j<=(2*i-1);j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void partialtriangle(int row,int offset)
{
    for(int i=1;i<=row;i++)
    {
        printf("%*s",offset,"");
        printf("%*s",row-i,"");
        for(int j=1;j<=(2*i+1);j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void stand(int row)
{
    for(int i=1;i<=2;i++)
    {
        printf("%*s",row,"");
        printf("*\n");
    }
}
int main(int argc, char const *argv[])
{
    int n,offset=1;
    scanf("%d",&n);
    fulltriangle(n+1);
    for(int j=n-1;j>=2;j--)
    {
        partialtriangle(j,offset);
        offset++;
    }
    stand(n);
    return 0;
}
