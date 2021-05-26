/*

Problem Link - https://www.codechef.com/COOK129C/problems/CSUBS

Problem Statement - Chef is playing a game where he has an array A of N integers, and an integer K. He looks at every subarray of length K, and writes its sum on a piece of paper. If a number appears as the sum of multiple subarrays of length K, then he only writes down that number once.

Chef is lazy and doesn't like to write numbers. You, being a friend of Chef, want to modify the array such that Chef will only write one number on his paper. In one modification you can choose any index i
and replace A[i] with any integer.

You need to find the minimum number of modifications required.

*/

#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve(int n, int k, vector<int> v){
  int ans = 0;
  for(int i=0; i<k; i++){
        int maximumOccurence = 0;
        map<int, int> ma;
        for(int j=i; j<n; j += k){
            maximumOccurence++;
            ma[v[j]]++;
        }
        int cur = maximumOccurence-1;
        for(auto ele:ma){
            cur = min(cur, maximumOccurence-ele.second);
        }
        ans += cur;
    }
    cout<<ans<<"\n";
}

signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int t   = 1;
  cin >> t;
  for(int i=1; i<=t; i++){           
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for(int j=1; j<=n; j++){
      cin>>v[j];
    }
    solve(n,k,v);
  }
  return 0;
}

// Tutorial Link to understand the solution - https://discuss.codechef.com/t/csubs-editorial/90045
