#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 , s2 ; 
    getline(cin , s1) ; 
    getline(cin, s2) ; 
    cout << s1.size() << " " << s2.size()<< endl ;
    cout << s1 + s2 << endl  ; 
    swap(s1[0], s2[0]) ; 
    cout << s1 << " " << s2 ; 
  
    return 0;
}
