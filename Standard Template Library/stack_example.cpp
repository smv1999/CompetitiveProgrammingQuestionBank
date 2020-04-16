/*
Stack Example using Standard Template Library
The operations performed on the stack are 
1. push
2. pop
3. peek(see the top element)
*/
#include<iostream>
#include<stack>
using namespace std;
int main(int argc, char const *argv[])
{
    stack <int> s;
    int n,e;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>e;
        s.push(e);
    }
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}
