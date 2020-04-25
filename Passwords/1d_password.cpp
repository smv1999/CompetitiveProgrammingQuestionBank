/*

Password Generation using 1-D Matrix
Problem Statement:

The password consists of N positive numbers. Also, there are some -1 placed in between the sequence purposefully
and there are certain conditions by which we can find those numbers.
The conditions are as follows:
1. If the numbers on both side of the "-1" are odd or even, then the absolute difference of the 
numbers is calculated.
2. Else if the numbers on both the side of the "-1" are different(one odd and other even), then the arithmetic mean of the numbers is 
calculated.And the floor of this result is stored in place of "-1"
3.


Input: The first number in the input is the number of elements
5 4 5 -1 2 4 

Output:
3 4 2 1 4

*/
#include<iostream>
#include<cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-2;i++)
    {
        if(a[i]==-1)
        {
        if((a[i-1]%2) == (a[i+1]%2))
        {
            a[i] = abs(a[i-1]-a[i+1]);
        }
        else{
            a[i] = floor((a[i-1]+a[i+1])/2);
        }
        }
      
    }
    for(int i=0;i<=n-2;i++)
    {
        if(a[i]!=1)
         a[i]= a[i]-1;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    return 0;
}
