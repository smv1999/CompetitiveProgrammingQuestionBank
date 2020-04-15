/*
Intersection of arrays using Two Pointer method

input 
3
10 17 57
6
2 7 10 15 57 246

output
10 57

We consider two pointers i,j for travsersing the array only once making the time complexity of the algoirithm
to O(m+n) rather than O(m*n) for a brute force approach where m and n are the array sizes.
*/
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n,m,p=0,q=0;
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
    while(p<n && q<m)
    {
        if(a[p]>b[q])
           q++;
        else if(a[p]<b[q])
           p++;
        else if(a[p]==b[q])
        {
            printf("%d ",a[p]);
            p++;
            q++;
        }
    }
    return 0;
}
