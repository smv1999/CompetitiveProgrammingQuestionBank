/*
Longest Progressive Sequence using Two Pointer method.

input 
10
1 1 2 1 2 3 12 13 5 10

output
1 2 3 12 13

We need to find the longest sequence in increasing order in the array.

*/
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n,start=0,end=0,curlen=1,maxlen=1,maxstart=0,maxend=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int j=1;j<n;j++)
    {
        if(a[j]>=a[j-1])
        {
            end = j;
            curlen = end - start + 1;
            if(curlen>maxlen)
            {
                maxlen = curlen;
                maxstart = start;
                maxend = end;
            }
        }
        else{
            start = j;
            end = j;
        }
    }
    // the indices maxstart to maxend indicates the sequence.
    for(int i=maxstart;i<=maxend;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
