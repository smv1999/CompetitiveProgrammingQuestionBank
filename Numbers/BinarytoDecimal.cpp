#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number-->";
    cin>>n;
    int temp=n,dec=0,base=1,t=1;
    while(temp){
        t=temp%10;
        dec=dec+t*base;
        base=base*2;
        temp/=10;
    }
    cout<<"The binary number "<<n<<"converted to decimal is "<<dec<<endl;
}
