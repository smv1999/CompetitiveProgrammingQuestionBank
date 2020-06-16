
/*
Find the larger number n greater than n2 that is divisible by n1.
For eg:
4   7 
output: 8
since 8 is the nearest larger number than 7 and it is divisible by 4.
*/
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n1,n2;
    cin>>n1>>n2;
    cout<<((n2/n1)+1)*n1;
    return 0;
}
