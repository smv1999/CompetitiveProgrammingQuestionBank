https://codeforces.com/contest/520/problem/B
    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
         long long int n,c=0,m;
        cin>>n>>m;
        while(m>n)
        {
            if(m%2)
                m++;
            else m/=2;
            c++;
        }
        cout<<c+n-m;
    }
