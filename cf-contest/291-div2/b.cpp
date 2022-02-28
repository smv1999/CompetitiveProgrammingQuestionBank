https://codeforces.com/contest/514/problem/B
    #include<bits/stdc++.h>
    using namespace std;
     
    double INF = 1e9 + 7;
     
    int main()
    {
        double n, x, y, a, b;
        cin >> n >> x >> y;
        unordered_set<double> s;
        double slope = 0;
        //pair<int , int> a[n];
        for( int i =0;i < n; ++i){
            cin >> a >> b;
            //a[i] = {a , b};
            if(x != a){
                slope = (y - b)/(x - a);
            } else {
                slope = INF;
            }
            //cout << slope << "\n";
            s.insert(slope);
        }
        cout << s.size();
        return 0;
    }
