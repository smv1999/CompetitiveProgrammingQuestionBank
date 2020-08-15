/*
Minimize the Sum - Problem Description

Given an array of integers, perform atmost K operations so that the sum of elements of final array is minimum. An operation is defined as follows -

Consider any 1 element from the array, arr[i].

Replace arr[i] by floor(arr[i]/2).

Perform next operations on updated array.

The task is to minimize the sum after atmost K operations.

Constraints

1 <= N, K <= 10^5.

*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void bubbleSort(int arr[], int n)
{
    int temp;
    for(int outer=0;outer<n-1;outer++)
    {
        for(int inner=0;inner<n-outer-1;inner++)
        {
            if(arr[inner]<arr[inner+1])
            {
                temp = arr[inner];;
                arr[inner] = arr[inner+1];
                arr[inner+1] = temp;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int n,k;
    int arr[n], arr_ind, count, sum=0;
    scanf("%d %d", &n, &k);
    for(arr_ind=0;arr_ind<n;arr_ind++)
        scanf("%d", &arr[arr_ind]);

    for(count=0;count<k;count++)    
    {
        bubbleSort(arr, n);
        arr[0] = floor(arr[0]/2);
    }
    for(arr_ind=0;arr_ind<n;arr_ind++)
        sum += arr[arr_ind];

    printf("%d", sum);
    return 0;
}
