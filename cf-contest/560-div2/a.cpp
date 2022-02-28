    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int n , x , y;
        cin >> n >> x >> y;
        string dig;
        cin >> dig;
        //puts(dig.c_str());
        int ans = 0;
        for( int i = 0; i < x; ++i){
            if( dig[n-1 - i ] != ( i == y ? '1' : '0')){
                ans++;
            }
        }
        cout << ans;
        return 0;
    }
