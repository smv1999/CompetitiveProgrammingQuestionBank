/*
Given an array, the aim is to print the sum of the elements in a
window of size k.The kth window of the input list is the integers from
index k to index k + window size - 1(inclusive).
*/
#include<iostream>

using namespace std;

int main()
{
    int n, k;
    cin>>n;
    int arr[n], index, sum=0;
    for(index=0;index<n;index++)
    {
        cin>>arr[index];
    }
    cin>>k;
    for(index=0;index<k;index++)
    {
        sum += arr[index];
    }
    cout<<sum<<" ";
    for(index=1;index<=n-k;index++)
    {
        sum -= arr[index-1];
        sum += arr[index+k-1];
        cout<<sum<<" ";
    }
    return 0;
}
