/*
Given an array of integers, find the first missing positive integer in linear time and constant space. In other words,
find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.

*/


#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<conio.h>

using namespace std;

// function prototype
void printArray(int arr[], int n);
int firstMissingNumber(int arr[], int n);


int firstMissingNumber(int arr[], int n)
{
    int index, temp;
    for(index=0;index<n;index++)
    {
        while(arr[index]>=1 && arr[index]<=n && arr[index]!=arr[arr[index]-1])
        {
            temp = arr[arr[index]-1];
            arr[arr[index]-1] = arr[index];
            arr[index] = temp;

        }
    }
    for(index=0;index<n;index++)
    {
        if((index+1)!=arr[index])
            return index+1;
    }
    return n+1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n], index, res;
    for(index=0;index<n;index++)
        cin>>arr[index];
    // finding the first positive missing number
    printf("\n");
    res = firstMissingNumber(arr,n);
    cout<<res;
    return 0;
}


