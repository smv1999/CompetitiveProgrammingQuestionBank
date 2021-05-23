/*
Problem Link - https://codeforces.com/contest/1527/problem/C

Problem Statement - The weight of a sequence is defined as the number of unordered pairs of indexes (i,j)
(here i<j) with same value (ai=aj). For example, the weight of sequence a=[1,1,2,2,1] is 4. The set of unordered pairs of indexes with same value are (1,2), (1,5), (2,5), and (3,4).

You are given a sequence a of n integers. Print the sum of the weight of all subsegments of a.
A sequence b is a subsegment of a sequence a if b can be obtained from a by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

*/

#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve(int n, vector<int> v){
  int ans = 0;
  map<int, int> toLeft;
  for(int i=1; i<=n; i++){
    if(toLeft[v[i]] != 0){
      int toRight = n-i+1;
      ans += toRight*toLeft[v[i]];
    }
    toLeft[v[i]] += i;
  }
  cout<<ans<<"\n";
}

signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int t   = 1;
  cin >> t;
  for(int i=1; i<=t; i++){           
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int j=1; j<=n; j++){
      cin>>v[j];
    }
    solve(n,v);
  }
  return 0;
}

// Tutorial Link to understand the solution - https://codeforces.com/blog/entry/90939
