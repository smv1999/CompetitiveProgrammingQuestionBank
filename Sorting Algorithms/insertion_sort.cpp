/*
Given an array, the elements of the array needs to be arranged in an increasing order.

Algorithm:
1. Traverse the array and keep track of the element to be inserted at each stage.
2. Store the element to be inserted in a variable.
3. Shift the elements accordingly to make the array sorted.

Input:
5 3 2 4 1
Output:
1 2 3 4 5

*/

#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {10, 20 ,30 , 40, 50, 60, 70, 80, 24, 44, 90};

    int size,safe,poi,shift;

    size = sizeof(arr)/sizeof(arr[0]);

    for(int addon = 1; addon<size;addon++)
    {

        for(poi=0;arr[addon]>arr[poi];poi++);

        safe = arr[addon];

        for(shift=addon-1; shift>=poi; shift--)
        {
            arr[shift+1] = arr[shift];
        }

        arr[poi] = safe;

    }
    for(int ind=0;ind<size;ind++)
        cout<<arr[ind]<<" ";
    return 0;
}
