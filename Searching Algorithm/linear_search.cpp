#include <iostream>

using namespace std;

int linearSearch(int arr[], int N, int k);

int main(int argc, char const *argv[])
{
    int N, k;
    cin >> N;
    int arr[N], index;
    for (index = 0; index < N; index++)
    {
        cin >> arr[index];
    }
    // key element to be searched
    cin >> k;
    int res = linearSearch(arr, N, k);
    if (res != -1)
        cout << "Element found at position:" << res;
    else
        cout << "Element Not Found!";
    return 0;
}

int linearSearch(int arr[], int N, int k)
{
    for (int index = 0; index < N; index++)
    {
        if (arr[index] == k)
            return index;
    }
    return -1;
}