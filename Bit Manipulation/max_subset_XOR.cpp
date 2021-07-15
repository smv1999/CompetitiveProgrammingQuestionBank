// Given an array of N positive integers. Find an integer denoting the maximum XOR subset value in the given array.
// Time complexity: O(n)


#include<bits/stdc++.h>
#define fl(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long int ll;

ll maxSubsetXOR(ll set[], ll n)
{
    ll index=0, max_pos, max;
    for (ll i = 31; i >= 0; i--)
    {
        max= LONG_MIN;
        max_pos= index;
         for (ll j = index; j < n; j++)
        {
            if ( (arr[j] & (1 << i)) != 0 && arr[j] > max )
                     {
                         max= arr[j];
                         max_pos= j;
                     }
               
        }
        if (max == LONG_MIN)
            continue;

        swap(arr[index], arr[max_pos]);
        max_pos = index;

        for (ll j=0; j<n; j++)
        {
            if (j != max_pos &&  (arr[j] & (1 << i)) != 0)
                arr[j] = arr[j] ^ arr[max_pos];
        }
        index++;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        ans ^= arr[i];
    return ans;
}

int main()
{ 
   fast;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n; cin>>n;
    ll arr[n];
    for(auto &x: arr)
        cin>>x;
     
    cout << maxSubsetXOR(arr, n);
    
    return 0;

}
