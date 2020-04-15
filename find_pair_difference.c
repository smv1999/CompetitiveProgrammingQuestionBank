/*
Find a pair difference k using Two Pointer method.

input 
6
2 7 10 15 57 246
47

output
10 57

We need to find the pair of numbers from the array such that their absolute difference is equal 
to a particular number k. The time complexity of the algorithm is O(n) compared to the brute force algorithm
that has a time complexity of O(n^2).
*/
#include<stdio.h>
#include<math.h>
int main(int argc, char const *argv[])
{
    int n,l,r,k;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    l = 0;
    r = 1;
    while(l<n && r<n)
    {
        if(abs(a[l]-a[r])>k)
            l++;
        else if(abs(a[l]-a[r])<k)
            r++;
        else{
            printf("The pair is (%d, %d)",a[l],a[r]);
            break;
        }
    }
    return 0;
}
