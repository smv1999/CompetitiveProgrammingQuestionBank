/*
String Rotation

input

career
3
L 2
R 3
L 2

output
NO

*/

#include <string.h>
#include <iostream>

using namespace std;
string shiftLeft(char* s)
{
    int len = strlen(s);
    std::string st = ((string)s).substr(1, len-1);
    return st+s[0];
}
string shiftRight(char* s)
{
    int len = strlen(s);
    std::string st = ((string)s).substr(0, len-1);
    return  s[len-1]+st;

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str[200],ch;
    int q,m;
    string firstchar="";
    cin>>str;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>ch>>m;
        if(ch=='L')
        {
            for(int j=0;j<m;j++)
            {
                firstchar+=shiftLeft(str)[0];
            }
        }
        else if(ch=='R')
        {
         for(int j=0;j<m;j++)
            {
                firstchar+=shiftRight(str)[0];
            }   
        }
    }
if (((string)str).find(firstchar) != std::string::npos) {
    cout << "YES";
}
else 
cout<<"NO";

    return 0;
}