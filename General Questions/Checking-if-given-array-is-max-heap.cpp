// C++ program to check whether a given array represents a max-heap or not
#include <limits.h>
#include <stdio.h>
#include <iostream>
using namespace std;
bool isHeap(int arr[], int n)
{
    // Start from root
    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        // If left child is greater, return false
        if (arr[2 * i + 1] > arr[i])
            return false;

        // If right child is greater, return false
        if (2 * i + 2 < n && arr[2 * i + 2] > arr[i])
            return false;
    }
    return true;
}
// Driver program
int main()
{
    int n;
    cout << "Enter the number of array elements-";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements-";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    isHeap(arr, n) ? printf("Yes, it represents a max-heap.") : printf("No");

    return 0;
}
