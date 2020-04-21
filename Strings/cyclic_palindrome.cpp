/*
Cyclic Palindrome 

input1
aaabb

output1
1

input2
abbb

output2
-1

The aim is to return the number of shifts necessary to make the string into a palindrome, 
if not possible, return -1.

*/
#include<iostream>
#include<string.h>
using namespace std;
bool isPal(const char* s)
{   
    int n = strlen(s);
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
}
string leftShift(char* s)
{
    int len = strlen(s);
    std::string thesub = ((string)s).substr(1, len - 1);
    return thesub + s[0];
}
string rightShift(char* s)
{
    int len = strlen(s);
    std::string thesub = ((string)s).substr(0, len - 1);
    return s[len-1] + thesub;
}
int main(int argc, char const *argv[])
{
    char str[200],word_left[200],word_right[200];
    cin>>str;
    int len = strlen(str);
    int shifts = 0,flag=0;
    strcpy(word_left,str);
    strcpy(word_right,str);
    while(shifts <= len/2)
    {
        if(isPal(word_left) || isPal(word_right))
        {
            flag = 1;
            break;
        }
        strcpy(word_left,leftShift(word_left).c_str());
        strcpy(word_right,rightShift(word_right).c_str());
        shifts++;
    }
    if(flag == 1)
    cout<<shifts;
    else
    cout<<-1;
    return 0;
}
