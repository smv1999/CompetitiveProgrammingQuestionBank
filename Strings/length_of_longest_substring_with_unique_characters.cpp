// Given a string S, find the length of its longest substring that does not have any repeating characters.
#include <bits/stdc++.h>
using namespace std;
  
int SubsequenceLength (string str) 
{
    //to store frequency of characters in the substrings
    int char_freq[256]={0};
    
    //left and right pointers of the substring
    int l=0, r=0;
    
    int max_length=0;
     
      
    while(l<=r && r<str.length())
    {
        char_freq[str[r]]++;
          
        while(char_freq[str[r]]>1)
        {
//           move the left wall of the window to the right
            char_freq[str[l]]--;
            l++;
             
        }
        char_freq[str[r]]= 1;
        max_length= max(max_length, r-l+1);
      
//       moving right wall of window to right
        r++;
    }
    return max_length;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout<<SubsequenceLength(str)<<"\n";
    }
    return 0;
}
 
