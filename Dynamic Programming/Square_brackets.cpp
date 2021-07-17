/*Problem statement => https://www.spoj.com/problems/SQRBR/  
  You are given:

  -> a positive integer n,
  -> an integer k, 1<=k<=n,
  -> an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
*/


#include<bits/stdc++.h>
using namespace std;
 
 
typedef string                 STR;
typedef long long              LL;
typedef vector<LL>             VLL;

#define all(a)             (a).begin(),(a).end()
#define dec(n)             cout<<fixed<<setprecision(n);
#define f(i,a,b)           for (i = a; i < b; i++)
#define fr(i,a,b)          for (i = a; i > b; i--)
#define rep(i,n)           for (i = 0 ; i < n; i++)
#define repr(i,n)          for (i = n - 1; i >= 0; i--)
#define fsort(a)            sort(a.begin(),a.end())
#define rsort(a)           sort(a.rbegin(),a.rend())      
 
const LL MOD     = 1000000007;
 
LL sq_brackets(LL n, LL k, VLL pos)
{
  vector<bool>h(2*n+1, 0);
  LL i;
  rep(i, k) h[pos[i]]=1; // hash array ti store the postions where opening bracket is must
  // dp array
  vector<vector<LL>>dp(2*n+1, vector<LL>(2*n+1, 0));
  // first position only one possible combination
  dp[0][0] = 1%MOD;
  // dp[i][j] represents i positions such that there are j more '[' brackets than ']' 
  for(LL i=1;i<=2*n;i++)
  {
    for(LL j=0;j<=2*n;j++)
    {
      //if that position has an opening bracket
      if(h[i])
      {
        // if diff(j) is not 0 then ith position has '[' hence dp[i][j]=dp[i-1][j-1]
        if(j!=0)
          dp[i][j] = dp[i-1][j-1]%MOD;
        else
          dp[i][j]=0; // no possibility if j==0
      }
      else
      {
        // both opening and closing brackets possible if h[i]!=1
        if(j!=0)
          dp[i][j] = (dp[i-1][j-1]%MOD + dp[i-1][j+1]%MOD)%MOD;
        else
          dp[i][j] = dp[i-1][j+1]%MOD;
      }
    } 
  }
  return dp[2*n][0];
}
int main()
{  
  int t=1;
  cin>>t;
  while(t--)
  {
    LL n,k,i;
    cin>>n>>k;
    VLL pos(k);
    rep(i,k)
      cin>>pos[i];
    LL ans = sq_brackets(n, k, pos);
    cout<<ans<<"\n";
  }
   return 0;
 } 