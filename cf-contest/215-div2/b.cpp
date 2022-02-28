https://codeforces.com/contest/368/problem/B
    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int n, m, temp;
        cin >> n >> m;
        int a[n+1] = {0};
        for(int i =1; i <= n ; ++i){
            cin >> a[i];
        }
        int dp[n+1] = {0};
        dp[n] = 1;
        unordered_set<int> s;
        s.insert(a[n]);
        for( int i = n - 1; i>0; --i){
            if(s.count(a[i])){
                dp[i] = dp[i+1];
            } else{
                dp[i] = dp[i+1] + 1;
                s.insert(a[i]);
            }
        }
        for( int i = 0;i < m; ++i){
            cin >> temp;
            cout << dp[temp] << "\n" ;
        }
        return 0;
    }
