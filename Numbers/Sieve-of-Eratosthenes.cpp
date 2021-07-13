// Sieve of Eratosthenes 
//time complexity = O(n* log(logn))

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long int ll;
const ll N= 10e6;
vector<bool> Prime(N+1,true);
using namespace std;

void sieve(){
    ll i,j;
    Prime[0]=Prime[1]=false;

    //adding this otpimization will reduce n/2 computations
    //since even no.s are not prime
    for(i=2;i<N+1;i+=2)
        Prime[i]=false;

    for(i=2;i<N+1;i++)
    {
        if(Prime[i])
            for(j=i*i;j<N+1;j+=i)
            if(Prime[j])
                Prime[j]=false;
    }
}

int main()
{ 
   fast;

ll i;
sieve();
for(i=1;i<100;i++)
    if(Prime[i])
        cout<<i<<" ";
return 0;

}
