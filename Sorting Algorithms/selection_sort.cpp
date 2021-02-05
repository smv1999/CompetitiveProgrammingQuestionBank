#include <iostream>

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_index;

    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        // Swap the minimum element found with the first element
        swap(&arr[min_index], &arr[i]);
    }
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
    selectionSort(arr, N);
    // printing the array elements
    for (index = 0; index < N; index++)
    {
        cout << arr[index] << " ";
    }
    return 0;
}
