https://codeforces.com/contest/158/problem/A
    #include "bits/stdc++.h"
    using namespace std;
    int main() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n,0);
        for(int i = 0; i < n ; ++i){
            cin >> a[i];
        }
        const int val = a[k-1];
        sort(a.begin() , a.end());
        int pos = lower_bound(a.begin() , a.end() , val) - a.begin();
        while(!a[pos] && pos < n){
            pos++;
        }
        cout << n - pos << "\n";
        return 0;
    }
