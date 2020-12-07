/*
 Given an array of size N-1 such that it can only contain distinct integers in the range of 1 to N. Find the missing element.
*/

#include <iostream>

using namespace std;

int main()
{
    //code
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n], index, sum = 0;
        for (index = 0; index < n - 1; index++)
        {
            cin >> arr[index];
            sum += arr[index];
        }
        cout << (n * (n + 1) / 2) - sum << endl;
    }
    return 0;
}