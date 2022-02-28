https://codeforces.com/contest/4/problem/C
#include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        long long t;
        cin>>t;
        cin.ignore();
        map<string,int> m;
        while(t--)
        {
            string s;
            getline(cin,s);
            if(m[s]==0)
            {
                cout<<"OK\n";
                m[s]++;
            }
            else
            {
                cout<<s<<m[s]<<endl;
                m[s]++;
            }
        }
    }
