#include <bits/stdc++.h>
using namespace std;
vector<int> duplicates(int arr[], int n);
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> ans = duplicates(a, n);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

vector<int> duplicates(int a[], int n)
{
    map<int, int> mp;
    vector<int> res;
    int index, flag = 0;
    for (index = 0; index < n; index++)
        mp[a[index]]++;
    for (auto i : mp)
    {
        if (i.second > 1)
        {
            res.push_back(i.first);
            flag = 1;
        }
    }
    if (!flag)
    {
        res.push_back(-1);
    }
    return res;
}
