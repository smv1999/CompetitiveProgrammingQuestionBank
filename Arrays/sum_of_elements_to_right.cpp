/*
Given an array, modify the array such that each element is replaced by the sum of the elements to the right of it
(in position).

For eg:

Input:
4 5 2 3 1
Output:
11 6 4 1 0


*/

#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {4, 5, 2, 3, 1};

    int size,sum=0;

    size = sizeof(arr)/sizeof(arr[0]);
    for(int ind=0;ind<size;ind++)
    {
        sum+=arr[ind];
    }

    for(int ind=0;ind<size;ind++)
    {
        arr[ind] = sum - arr[ind];
        sum = arr[ind];
    }

    for(int ind=0;ind<size;ind++)
        cout<<arr[ind]<<" ";
    return 0;
}
