/*
Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller
and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.
*/

// Brute force approach

/*
#include <iostream>
using namespace std;

int isRequired(int arr[], int n)
{
    int index;
    bool leftFlag = false, rightFlag = false;

    for (index = 1; index < n - 1; index++)
    {
        for (int left = 0; left < index; left++)
        {
            if (arr[left] < arr[index])
                leftFlag = true;
            else
            {
                leftFlag = false;
                break;
            }
        }
        for (int right = index + 1; right <= n - 1; right++)
        {
            if (arr[right] > arr[index])
                rightFlag = true;
            else
            {
                rightFlag = false;
                break;
            }
        }
        if (leftFlag && rightFlag)
            break;
    }

    if (leftFlag && rightFlag)
        return arr[index];
    return -1;
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n], index;

        for (index = 0; index < n; index++)
            cin >> arr[index];
        int result = isRequired(arr, n);

        cout << result << endl;
    }
    return 0;
}
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int great[n];
        int small[n];

        great[0] = arr[0];
        for (int i = 1; i < n; i++)
            great[i] = max(great[i - 1], arr[i]);

        small[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            small[i] = min(small[i + 1], arr[i]);

        int res = -1;
        for (int i = 1; i < n - 1; i++)
        {
            if (great[i] == small[i])
            {
                res = great[i];
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}