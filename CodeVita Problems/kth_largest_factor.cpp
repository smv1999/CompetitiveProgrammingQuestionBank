/*
Kth Largest Factor
 A positive integer d is said to be a factor of another positive integer N if when N is divided by d, the remainder obtained is zero. For example, for number 12, there are 6 factors 1, 2, 3, 4, 6, 12. Every positive integer k has at least two factors, 1 and the number k itself.Given two positive integers N and k, write a program to print the kth largest factor of N.

Input Format: The input is a comma-separated list of positive integer pairs (N, k).

Output Format: The kth highest factor of N. If N does not have k factors, the output should be 1.

Constraints:

1<N<10000000000
1<k<600.
You can assume that N will have no prime factors which are larger than 13.

*/
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,k, count=0;
    cin>>n>>k;
    for(int num=1;num<=n/2;num++)
    {
        if(n%num==0)
        {
            count++;
        }
        if(count==k+1)
        {
            cout<<num;
            break;
        }
    }
    if(count<k)
        cout<<1;
    return 0;
}
