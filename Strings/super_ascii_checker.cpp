/*
Super ASCII String Checker

input
abbcccdddd

output
Yes

We solve this problem using the "Bucketing Algorithm".

*/
#include<iostream>
#include<string.h>
using namespace std;
int main(int argc, char const *argv[])
{
    char str[200];
    cin>>str;
    int len = strlen(str);
    int arr[26];
    for(int i=0;i<26;i++)
    {
        arr[i]=0;
    }
    int flag = 1;
    for(int i=0;i<len;i++)
    {
        arr[str[i]-97]++;
    }
    for(int i=0;i<26;i++)
    {
        if(arr[i]!=0 && arr[i]!=i+1)
        {
            flag = 0;
            break;
        }
    }
    if(flag==1)
    cout<<"Yes";
    else 
    cout<<"No";
    return 0;
}
