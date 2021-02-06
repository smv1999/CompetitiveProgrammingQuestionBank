/*
Given an array of integers, sort the array according to frequency of elements. That is elements that have higher 
frequency come first. If frequencies of two elements are same, then smaller number comes first.

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sortByFreq(int arr[], int n);

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        int a[n + 1];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> v;
        v = sortByFreq(a, n);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends

//Complete this function
//Return the sorted array

bool sortbysec(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return (a.second > b.second);
    else
        return (a.first < b.first);
}
vector<int> sortByFreq(int arr[], int n)
{
    //Your code here
    map<int, int, greater<int>> mp;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    vector<pair<int, int>> v;

    for (auto it = mp.begin(); it != mp.end(); it++)
        v.push_back(make_pair(it->first, it->second));

    sort(v.begin(), v.end(), sortbysec);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        int k = it->second;

        while (k--)
        {
            res.push_back(it->first);
        }
    }

    return res;
}