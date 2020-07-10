/*
Given an array, the elements of the array are to be arranged in an increasing order.

Algorithm:
1. Traverse the array, compare each element with the adjacent element,
2. swap them if(cur_element > next_element) else continue the traversal
3. Repeat the above step till the array is completely sorted.

Input:
5 1 4 2 3

Output:
1 2 3 4 5

*/

#include<iostream>

using namespace std;

void bubbleSort(int arr[], int size)
{
    int temp;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 1, 4, 2, 3};

    int size;

    size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,size);

    for(int ind=0;ind<size;ind++)
        cout<<arr[ind]<<" ";
    return 0;
}
