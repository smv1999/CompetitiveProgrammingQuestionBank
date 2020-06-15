#include<bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    string s;
    cin>>n;
    while(true)
    {
        s += to_string(n%2);
        if(n==1) break;
        n = n / 2;
    }
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}
