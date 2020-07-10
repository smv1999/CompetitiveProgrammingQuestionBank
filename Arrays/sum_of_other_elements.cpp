/*
Given an array, modify the array such that each element in the array is replaced by the sum of the other elements 
in the array.
For eg:

Input:
1 4 5 3 2
Output:
14 11 10 12 13

*/

#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {1,4,5,3,2};
    int size,sum=0;

    size = sizeof(arr)/sizeof(arr[0]);
    for(int ind = 0;ind < size;ind++)
    {
        sum+=arr[ind];
    }

    for(int ind=0;ind<size;ind++)
    {
        arr[ind] = sum - arr[ind];       
    }

    for(int ind=0;ind<size;ind++)
        cout<<arr[ind]<<" ";
    return 0;
}
