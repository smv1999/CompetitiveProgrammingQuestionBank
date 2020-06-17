/*
Given an array containing N elements where 1<=N<=100000, and given Q queries, for each query increment the subarray 
[L,R] by 1. At the end, print the final elements.


*/

// THIS SOLUTION IS INCOMPLETE

#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N,Q,l,r,i=0;
    int arr[N];
    int B[N]={0};
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }

    cin>>Q;
    while(Q--)
    {
        cin>>l>>r;
        B[l]+=1;
        B[r+1]-=1;
    }
    for(i=0;i<N;i++)
    {
        arr[i] = 
    }
    return 0;
}
