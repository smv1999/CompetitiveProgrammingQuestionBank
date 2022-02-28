https://codeforces.com/contest/1645/problem/B
#include "bits/stdc++.h"
using namespace std;
int main() {
    int n;
    cin >> n;
    string t;
    cin >> t;
    string ans = "";
    int k = 1;
    for( int i = 0; i < n ; i+=k){
        k++;
        ans += t[i];
    }
    cout << ans ;
    return 0;
}

