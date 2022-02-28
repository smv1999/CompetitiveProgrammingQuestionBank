https://codeforces.com/contest/1645/problem/A
#include "bits/stdc++.h"
using namespace std;
int main() {
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int a[n];
        for( int i = 0; i < n ; ++i){
            cin >> a[i];
        }
        for( int i = 0; i + 1 < n; ++i){
            if(a[i] != a[i+1]){

                if(i + 2 < n && a[i] != a[i+2]){
                    cout << i + 1 << "\n";
                } else {
                    cout << i+1 + 1 << "\n";
                }
                break;
            }
        }
    }
    return 0;
}

