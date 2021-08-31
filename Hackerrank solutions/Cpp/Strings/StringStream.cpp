#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> print(string str)
{
    stringstream s ; 
    s<< str ; 
    vector<int> res ; 
    int temp ; 
    char ch ;
    while(s>>temp){
        res.push_back(temp);
        s>>ch ;
    }
    return res ;
}
int main ()
{
    string s ; 
    cin >> s; 
    vector<int> vec = print(s);
    for(int i=0 ; i<vec.size() ; i++ )
        cout << vec[i] << endl; 
}
