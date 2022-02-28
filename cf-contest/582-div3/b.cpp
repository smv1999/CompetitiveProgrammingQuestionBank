        #include<bits/stdc++.h>
        using namespace std;
         
        int main()
        {   
            int t;
            cin >> t;
            while(t--){
                int n;
                cin >> n;
                int a[n];
                for( int i = 0; i < n ; ++i){
                    cin >> a[i];
                }
                int ans = 0, minimum = a[n-1];
                for( int i = n-2; i >= 0; --i){
                    if( a[i] <= minimum ){
                        minimum = a[i];
                    } else {
                        ans++;
                    }
                }
                cout << ans << "\n";
            }
            return 0;
        }
