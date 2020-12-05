#include <bits/stdc++.h>
using namespace std;

int remove_duplicate(int[], int);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int a[N];
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }

        int n = remove_duplicate(a, sizeof(a) / sizeof(a[0]));

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}

int remove_duplicate(int A[], int N)
{
    int temp[N], j = 0;
    for (int index = 0; index < N - 1; index++)
    {
        if (A[index] != A[index + 1])
        {
            temp[j++] = A[index];
        }
    }
    temp[j++] = A[N - 1];
    for (int index = 0; index < j; index++)
    {
        A[index] = temp[index];
    }
    return j;
}