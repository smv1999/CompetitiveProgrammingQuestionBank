https://codeforces.com/contest/519/problem/B
    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int n, temp;
        cin >> n;
        int sum1 = 0 , sum2 = 0;
        //unordered_set<int> s1 , s2; : Cannot use set because of duplicate elements
        for( int i =0; i <n ; ++i){
            cin >> temp;
            sum1 += temp;
        }
     
        for( int i = 0; i < n-1; ++i){
            cin >> temp;
            sum1 -= temp;
            sum2 += temp;
        }
     
        cout << sum1 << "\n";
     
        for( int i = 0; i < n-2; ++i){
            cin >> temp;
            sum2 -= temp;
            //s1.insert(temp);
        }
        cout << sum2 << "\n";    
     
        return 0;
    }
