/*
Given two arrays: arr1[0..m-1] of size m and arr2[0..n-1] of size n. Task is to check whether arr2[] is a subset
of arr1[] or not. Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.
*/
#include <iostream>
#include <unordered_set>
using namespace std;

bool isSubset(int arr1[], int arr2[], int m, int n)
{
    unordered_set<int> s;
    for (int index = 0; index < m; index++)
    {
        s.insert(arr1[index]);
    }
    for (int index = 0; index < n; index++)
    {
        if (s.find(arr2[index]) == s.end())
            return false;
    }
    return true;
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, flag = 0;
        cin >> m >> n;
        int arr1[m], arr2[n];
        for (int index = 0; index < m; index++)
        {
            cin >> arr1[index];
        }
        for (int index = 0; index < n; index++)
        {
            cin >> arr2[index];
        }
        if (isSubset(arr1, arr2, m, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}