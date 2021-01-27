#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

void countingSort(int arr[], int n)
{
    int k = *max_element(arr, arr + n);
    int countArr[k + 1];
    int sortedArr[n];
    for (int i = 0; i < k + 1; i++)
        countArr[i] = 0;
    for (int i = 0; i < n; i++)
        countArr[arr[i]]++;
    for (int i = 1; i <= k; i++)
        countArr[i] = countArr[i] + countArr[i - 1];
    for (int i = n - 1; i >= 0; i--)
        sortedArr[--countArr[arr[i]]] = arr[i];
    for (int i = 0; i < n; i++)
        arr[i] = sortedArr[i];
}

//Print the sorted array
void printSortedArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int arr[] = {9, 3, 7, 5, 6, 4, 8, 2, 9, 0, 1, 1, 6, 12, 9}; // Unsorted Array
    int arr_size = sizeof(arr) / sizeof(arr[0]);                //Getting array size
    countingSort(arr, arr_size);                                // Send the array to countingSort
    printSortedArray(arr, arr_size);                            // Print the sorted array
    return 0;
}
