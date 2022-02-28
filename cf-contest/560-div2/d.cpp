    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int t , n;
        cin >> t ;
        while(t--){
            cin >> n;
            vector<int> a(n, 0);
            long long MAX = -1 , MIN = INT_MAX;
            for( int i = 0; i < n ; ++i){
                cin >> a[i];
                MAX = max(MAX , a[i]*1ll);
                MIN = min(MIN , a[i]*1ll);
            }
            sort(a.begin(), a.end());
            long long maybe = MAX*MIN ;
            vector<int> divisors;
            for( long long div = 2; div*div <= maybe; ++div){
                if(maybe%div == 0){
                    divisors.push_back(div);
                    if(div*div != maybe){
                        divisors.push_back(maybe/div);
                    }
                    //divisors.push_back(maybe/div);
                }
            }
            sort(divisors.begin(), divisors.end());
            if( divisors == a){
                cout << maybe << "\n";
            } else {
                puts("-1");
            }
        }
        return 0;
    }
