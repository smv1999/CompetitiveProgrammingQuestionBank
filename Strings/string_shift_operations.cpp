/*
String Shift Operations
-----------------------

Left and Right Shift Operations by a particular length c

*/
#include<iostream>
#include<string.h>
using namespace std;

string shiftLeft(char* s,int c)
{
    int len = strlen(s);
    int k=0;
    string a="";
    for(int i=0;i<c;i++)
    {
        a+=s[k++];
    }
    std::string st = ((string)s).substr(k, len-1);
    return st+a;
}
string shiftRight(char* s,int c)
{
    int len = strlen(s);
    int k = len-1;
    string a="";
    for(int i=0;i<c;i++)
    {
        a+=s[k--];
    }
    std::string st = ((string)s).substr(0, k+1);
    return  a+st;
}