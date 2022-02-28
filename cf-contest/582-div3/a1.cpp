// O(n) solution
        #include<bits/stdc++.h>
        using namespace std;
         
        int main()
        {   
            // O(N) Approach        
            const int INF = 1e9 + 7;
            int n, first_odd = INF, first_even = INF;
            cin >> n;
            int a[n];
            for( int i = 0; i <n ; ++i){
                cin >> a[i];
                if(a[i]&1){
                    first_odd = a[i];
                } else {
                    first_even = a[i];
                }
            } 
            //sort(a, a+n);
            // nth_element( a , a + n/2, a + n);
            // int median = a[n/2];
            int ans = INT_MAX;
            // for( int i : a){
            //     ans += abs(i - median)%2;
            // }
            // int val[n] = {0}, temp = 0;
            // for( int i = 0; i < n; ++i){
            //     temp = 0;
            //     for( int j = 0; j < n ; ++j){
            //         temp += abs(a[i] - a[j])%2;
            //     }
            //     val[i] = temp;
            // }
     
            int val1 = 0, val2 = 0;
            for( int i : a){
                val1 += abs(first_even - i)%2;
                val2 += abs(first_odd - i)%2;
            }
     
            ans = min(val1 , val2);
         
            // for( int i = 0; i < n ; ++i){
            //     ans  = min(ans , val[i]);
            // }
            cout << ans ;
            return 0;
        }
