https://codeforces.com/contest/1165/problem/B
    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int n;
        cin >> n;
        vector<int> a(n ,0);
        for( int i = 0; i < n ; ++i){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
        int k = 1, index = lower_bound(a.begin(), a.end(), k) - a.begin();
     
        while(index < n){
            //cout << index << "\t";
            index = lower_bound(a.begin()+index + 1, a.end(), ++k) - a.begin();
        }
        cout << k - 1 ;
        return 0;
    }
