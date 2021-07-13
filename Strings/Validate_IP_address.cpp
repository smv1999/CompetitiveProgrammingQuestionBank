/*************************************************************************


Write a program to Validate an IPv4 Address. 

According to Wikipedia, IPv4 addresses are canonically represented in 
dot-decimal notation, which consists of four decimal numbers, 
each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1 . 


The generalized form of an IPv4 address is (0-255).(0-255).(0-255).(0-255). 
Here we are considering numbers only from 0 to 255 and 
any additional leading zeroes will be considered invalid.

Your task is  to complete the function isValid which returns 1, 
if the ip address is valid else returns 0. 

The function takes a string s as its only argument .

**************************************************************************/


SOLUTION (in C++):

#include<bits/stdc++.h>

using namesapce std;

int isValid(string s)
{
    s += '.';
    int countDots = 0;
    string str = "";
    for(int i = 0;i<s.length();i++)
    {
        if(s[i] != '.')
        {
           if(s[i] >= 48 && s[i] <= 57)
                 str += s[i];
           else
                 return 0;
        }
        if(s[i] == '.')
        {
           if(str[0] == '.' && str.length() > 1)
              return 0;
           stringstream obj(str);
           int x = 0;
           obj>>x;
           if(x<0 || x>255)
               return 0;
           if(str.size() == 0)
               return 0;
           countDots++;
           str = "";
    }
    if(countDots == 4)
       return 1;
    else 
       return 0;
}


int main()
{
   string s;
   cin>>s;
   int k = isValid(s);
   if(k == 0)
     cout<<"Valid"<<endl;
   else
     cout<<"Not Valid"<<endl;
   return 0;
}