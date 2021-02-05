#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot element
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void sorter(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        sorter(arr, low, pi - 1);
        sorter(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int n)
{
    sorter(arr, 0, n - 1);
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int arr[N], index;
    for (index = 0; index < N; index++)
    {
        cin >> arr[index];
    }
    quickSort(arr, N);
    // printing the array elements
    for (index = 0; index < N; index++)
    {
        cout << arr[index] << " ";
    }
    return 0;
}
