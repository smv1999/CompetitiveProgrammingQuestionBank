#include <iostream>
using namespace std;
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>
int main() {
    int t,n,s,p,v,q;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=0;
            cin>>s>>p>>v;
            while((p-=s)>0)
            {
                p--;
                arr[i]++;
            }
            arr[i]*=v;
        }
        sort(arr,arr+n);
        cout<<arr[n-1]<<"\n";
    }
  
    
	return 0;
}
