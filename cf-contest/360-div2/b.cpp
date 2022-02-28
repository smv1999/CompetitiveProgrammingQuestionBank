https://codeforces.com/contest/688/problem/B
    #include "bits/stdc++.h"
    using namespace std;
    int main() {
        string n;
        cin >> n;
        string val(n.rbegin(), n.rend()); 
        //reverse(val.begin(), val.end());
        cout << n + val;
    }
