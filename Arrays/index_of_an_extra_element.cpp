#include <bits/stdc++.h>
using namespace std;
int findExtra(int a[], int b[], int n);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }
        cout << findExtra(a, b, n) << endl;
    }
}

int findExtra(int a[], int b[], int n)
{
    for (int index = 0; index < n; index++)
    {
        if (a[index] != b[index])
            return index;
    }
}