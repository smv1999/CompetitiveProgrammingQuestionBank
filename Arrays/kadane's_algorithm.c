/*
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

For Example:

Input:
N = 5
arr[] = {1,2,3,-2,5}
Output: 9
*/
#include<stdio.h>
#include<limits.h>

int main()
{

    int n;
    scanf("%d", &n);
    int arr[n], index=0, max_so_far=INT_MIN, temp_max=0;
    for(index=0;index<n;index++)
        scanf("%d", &arr[index]);
    for(index=0;index<n;index++)
    {
        temp_max += arr[index];
        if(temp_max>max_so_far)
            max_so_far = temp_max;
        if(temp_max<0)
            temp_max = 0;

    }
    printf("%d", max_so_far);
    return 0;
}
