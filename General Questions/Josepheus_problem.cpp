// Given the total number of persons n and a number k,
// which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.

// The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle,
//  you are the last one remaining and survive.

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> vec, int index, int k, int &ans)
{ // Base Case
    if (vec.size() == 1)
    {
        ans = vec[0];
        return;
    }

    index = (index + k) % vec.size(); // covering the case when index overflows the array.
    vec.erase(vec.begin() + index);   // removing the Kth element
    solve(vec, index, k, ans);        // Recursive call
}

int main()
{
    int n = 3, k = 2;
    vector<int> v;
    k--;
    int ans;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    solve(v, 0, k, ans);
    cout << ans;
    return ans;
}