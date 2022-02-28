https://codeforces.com/contest/1213/problem/A
// O(n^2) solution
    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int n;
        cin >> n;
        int a[n];
        for( int i = 0; i <n ; ++i){
            cin >> a[i];
        } 
        //sort(a, a+n);
        // nth_element( a , a + n/2, a + n);
        // int median = a[n/2];
        int ans = INT_MAX;
        // for( int i : a){
        //     ans += abs(i - median)%2;
        // }
        int val[n] = {0}, temp = 0;
        for( int i = 0; i < n; ++i){
            temp = 0;
            for( int j = 0; j < n ; ++j){
                temp += abs(a[i] - a[j])%2;
            }
            val[i] = temp;
        }
     
        for( int i = 0; i < n ; ++i){
            ans  = min(ans , val[i]);
        }
        cout << ans ;
        return 0;
    }
