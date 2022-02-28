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
        sort(a.rbegin(), a.rend());
        int k = 1;
        for( int k = 1; ; ++k){
            while(!a.empty() && a.back() < k){
                a.pop_back();
            }
            if(a.empty()){
                cout << k - 1;
                return 0;
            }
            a.pop_back();
        }
        cout << k - 1;
        return 0;
    }
