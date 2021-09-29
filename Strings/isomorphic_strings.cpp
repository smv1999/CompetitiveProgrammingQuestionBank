// Given two strings, check if these two strings are isomorphic to each other. 
// Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2. 

#include<bits/stdc++.h>
#define fl(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long int ll;

bool areIsomorphic(string str1, string str2)
    {
      //   strings with unequal lengths cannot be isomorphic
        if(str1.length()!=str2.length())
            return false;
        
      //   for counting frequencies of each character in both the srrings
        int str1_freq[256]={0};
        int str2_freq[256]={0};

        for (int i=0; i< str1.length(); i++)
        {
               str1_freq[str1[i]]++;
               str2_freq[str2[i]]++;
               
               // the moment frequencies of current element in both the strings become unequal, we know that they are not isomorphic
               if (str1_freq[str1[i]]!= str2_freq[str2[i]])
                    return false;
        }
        
        return true;
                
    }

int main()
{ 
   fast;

 int t;
    cin>>t;
    string str1,str2;
    while (t--) 
    {
        cin>>str1;
        cin>>str2;
        
        if(areIsomorphic(str1,str2))
            cout<<str1<<" and "<<str2<<" are Isomorphic Strings "<<endl;
        else
            cout<<str1<<" and "<<str2<<" are not Isomorphic Strings "<<endl;
    }
    return 0;
}
