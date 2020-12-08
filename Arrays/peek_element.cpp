/*
A peak element in an array is the one that is not smaller than its neighbours.
Given an array of size N, find the index of any one of its peak elements.
*/
#include <bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int n)
{

    int index = 0, resIndex;
    if (arr[index] > arr[index + 1])
    {
        resIndex = index;
    }
    for (index = 1; index < n - 1; index++)
    {
        if (arr[index] > arr[index - 1] && arr[index] > arr[index + 1])
        {
            resIndex = index;
        }
    }
    if (arr[n - 1] > arr[n - 2])
    {
        resIndex = n - 1;
    }
    return resIndex;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool f = 0;
        int A = peakElement(a, n);

        if (n == 1)
            f = 1;
        else if (A == 0 and a[0] >= a[1])
            f = 1;
        else if (A == n - 1 and a[n - 1] >= a[n - 2])
            f = 1;
        else if (a[A] >= a[A + 1] and a[A] >= a[A - 1])
            f = 1;
        else
            f = 0;

        cout << f << endl;
    }

    return 0;
}