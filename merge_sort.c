/*
Merge Sort
input 
4
11 22 33 44
10 20 30 40
 
output
10 11 20 22 30 33 40 44

We need to print the merged sorted arrays of the individual sorted arrays given.
*/
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n,m,ap=0,bp=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    int b[m];
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    while(ap<n && bp<m)
    {
        if(a[ap]>b[bp])
        {
            printf("%d ",b[bp]);
            bp++;
        }
        else if(a[ap]<b[bp])
        {
            printf("%d ",a[ap]);
            ap++;
        }
    }
    if(ap<=n-1)
    {
        for(int i=ap;i<n;i++)
            printf("%d ",a[i]);
    }
    if(bp<=m-1)
    {
        for(int i=bp;i<m;i++)
        printf("%d ",b[i]);
    }
    return 0;
}
