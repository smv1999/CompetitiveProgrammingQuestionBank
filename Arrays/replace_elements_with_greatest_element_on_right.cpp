/*
Src : LeetCode
--------------

Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace 
the last element with -1.

After doing so, return the array.
*/

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int n = arr.size();
        int max = arr[n - 1];
        vector<int> res(n);
        res[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            res[i] = max;
            if (arr[i] > max)
                max = arr[i];
        }
        return res;
    }
};