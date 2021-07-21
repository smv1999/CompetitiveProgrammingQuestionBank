#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll value(ll a){

    ll count=a;
    while(a%2==0){
        a/=2;
        count+=a;
    }
    for(ll i=3;i*i<a+2;i+=2)

    {     while(a%i==0){
                    a/=i;
                    count+=a;
                }
                
             
    }
    if(a>2) count+=1;

    return count;
}
 

int main()
{
	/* code */
    IO
	 
	 ll a,n,sum=0;
     cin>>n;
      
     for(int i=0;i<n;i++)
     {
        cin>> a;
        sum+= value(a);
     }
     cout<<sum;
	 
	return 0;
	 
}