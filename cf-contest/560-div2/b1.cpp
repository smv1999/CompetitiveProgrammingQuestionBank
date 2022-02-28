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
        int k = 1;
        for( int i = 0; i < n ; ++i){
            if(a[i] >= k){
                k++ ;
            }
        }
        cout << k - 1;
        return 0;
    }
