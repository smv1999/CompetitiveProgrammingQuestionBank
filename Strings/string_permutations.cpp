// Problem: Print all permutations of string

// Input: ABC
// Output: ABC ACB BAC BCA CBA CAB

// Concept: Backtracking

#include<bits/stdc++.h>
#define fl(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long int ll;
vector<string> permutations;

vector<string> permute(string str, ll l, ll r)
{
   if(l==r)
      {
         permutations.push_back(str);
         return permutations;
      }
   for(ll i=l; i<=r; i++)
   {
      swap(str[l], str[i]);
      permute(str, l+1, r);
      swap(str[l], str[i]);
   }
   return permutations;
}

int main()
{ 
   fast;

string str;
cin>>str;

vector <string> ans= permute(str, 0, str.length()-1);

for(auto x: ans)
   cout<<x<<" ";

return 0;

}
