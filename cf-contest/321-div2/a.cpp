https://codeforces.com/contest/580/problem/A
        #include<bits/stdc++.h>
        using namespace std;
         
        int main()
        {   
            int n;
            int temp , prev = -1; 
            cin >> n;
            int ans = INT_MIN, val = 0;
            for( int i = 0; i < n; ++i){
                cin >> temp;
                if(temp >= prev){
                    val++;
                } else  {
                    val = 1;
                }
                prev = temp ;
                ans = max(ans , val);
            }
            cout << ans ;
            return 0;
        }
