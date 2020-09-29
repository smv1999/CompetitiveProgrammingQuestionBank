/*
Given an array of N elements. The aim is to print the elements whose left sum and 
right sum are equal. Left sum means the sum of the elements present to the left of
the current element and right sum means the sum of the elements present to the right 
of the the current element.
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int arr[N+1], index, totalSum[N+1];
    totalSum[0] = 0;
    for(index=1;index<=N;index++)
    {
        cin>>arr[index];
        totalSum[index] = totalSum[index-1] + arr[index]; 
    }
    for(index=1;index<=N;index++)
    {
        if((totalSum[index]-arr[index]) == (totalSum[N]-totalSum[index]))
            cout<<arr[index]; 
    }
    

    return 0;
}