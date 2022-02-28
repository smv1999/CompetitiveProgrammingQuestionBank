#include "bits/stdc++.h"
using namespace std;
int main() {
    int n;cin >> n;
    int a[n];
    unordered_set<int> s;
    for( int i = 0; i < n ; ++i){
        cin >> a[i];
        s.insert(a[i]);
    }
    if( s.size() == n){
        cout << n ;
        return 0;
    }
    int ans = s.size();
    for( int i = 0; i < n; ++i){
        if(!s.count(a[i] + 1)){
            ans++;
            s.insert(a[i] + 1);
        } else if(a[i] > 1 && !s.count(a[i] - 1)) {
            ans++;
            s.insert(a[i]-1);
        }
    }
    cout << ans ;
    return 0;
}

