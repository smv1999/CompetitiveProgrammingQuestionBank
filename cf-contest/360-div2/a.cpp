#include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {   
        int n , d;
        cin >> n >> d;
        string temp ;//string str[d];
        int val = 0;
        int ans = INT_MIN;
        for( int i = 0;i < d; ++i){
            cin >> temp;
            if(temp.find("0") != string::npos){
                val++;
            } else {
                val = 0;
            }
            ans = max(ans , val);
        }
        cout << ans ;
        return 0;
    }
