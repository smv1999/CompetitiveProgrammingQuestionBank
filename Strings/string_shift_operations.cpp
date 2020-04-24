/*
String Shift Operations
-----------------------

Left and Right Shift Operations by a particular length c

*/
#include<iostream>
#include<string.h>
using namespace std;

string shiftLeft(string s,int c)
{
   return s.substr(c) + s.substr(0,c);
}
string shiftRight(string s,int c)
{
    return s.substr(c+1) + s.substr(0,c+1);
}
int main(int argc, char const *argv[])
{
    cout<<shiftRight("Hello",2);
    cout<<shiftLeft("Hello",2);
    return 0;
}
