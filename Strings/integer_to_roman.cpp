// Convert an integer number n to roman number.

#include<bits/stdc++.h>
#define fl(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long int ll;

string int_to_roman(ll n)
{
   string str="";
   // store all base values in vector in descending order
   vector <int > v ={1000,900,500,400,100,90,50,40,10,9,5,4,1};

   // store roman numeral equivalent of each base value using map
   map <int, string> m ={{1000,"M"}, {900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};

   //now find the largest base value 
   //dividing the number and repeat the symbol accordingly
  
   for(auto x: v)
   {
      if(n>0)
      {
         int i= n/x;
         n= n%x;
         while(i--)
            str+= m[x];   //repeating the correspoding roman symbol
      }
      else
      return str;
   }
   return str;
}

int main()
{ 
   fast;

ll n; cin>>n;
cout<<int_to_roman(n);

return 0;

}
