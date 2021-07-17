/***************************************************************************

A Program to check if strings are rotations of each other or not.

***************************************************************************/

SOLUTION (in C++):

//Suppose there are two strings s1 = "devincept" and s2 = "vinceptde", 

//to check if s2 is rotation of s1, what we can do is, add s1 to itself

// Assign it to another string s3 = s1 + s1

//If s2 is a substring of s1, it is rotation of s1.



#include<bits/stdc++.h>

using namespace std;

int main()
{
   string s1, s2, s3;
   cout<<"Enter the strings"<<endl;
   cin>>s1;
   cin>>s2;
   s3 = s1 + s1;
   if(s3.find(s2) != -1 && s1 != s2)//if s2 is not a substringof s1 then find returns -1
   {
      cout<<s2<<" is rotation of "<<s1;
   }
   else
   {
      cout<<s2<<" is not rotation of "<<s1;
   }
   return 0;
}