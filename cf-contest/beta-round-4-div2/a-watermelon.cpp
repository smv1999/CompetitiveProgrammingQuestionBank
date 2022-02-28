#include "bits/stdc++.h"
    using namespace std;
    int main() {
        long long n;
        cin >> n;
        if(n <= 2){
            cout << "NO\n";
            return 0;
        } else{
            if(n&1)
                cout << "NO";
            else
                cout << "YES";
        }
    }
