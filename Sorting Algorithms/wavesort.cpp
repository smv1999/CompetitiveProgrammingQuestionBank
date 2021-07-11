/*Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array and return it
In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....

Example 1:

Input:
n = 5
arr[] = {1,2,3,4,5}
Output: 2 1 4 3 5
Explanation: Array elements after 
sorting it in wave form are 
2 1 4 3 5.

Example 2:

Input:
n = 6
arr[] = {2,4,7,8,9,10}
Output: 4 2 8 7 10 9
Explanation: Array elements after 
sorting it in wave form are 
4 2 8 7 10 9.


Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ n ≤ 106
0 ≤ arr[i] ≤107  


solution : */

#include<iostream>
using namespace std;
 
// A utility method to swap two numbers.
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
// This function sorts arr[0..n-1] in wave form, i.e., arr[0] >=
// arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5] ....
void WaveSort(int arr[], int n)
{
    // Traverse all even elements
    for (int i = 1; i < n; i+=2)
    {
        // If current even element is smaller than previous
        if ( arr[i-1] < arr[i] )
            swap(&arr[i], &arr[i-1]);
 
        // If current even element is smaller than next
        if (arr[i] > arr[i+1] && i<= n-2 )
            swap(&arr[i], &arr[i + 1]);
    }
}
 

int main()
{
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    WaveSort(arr, n);
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}

