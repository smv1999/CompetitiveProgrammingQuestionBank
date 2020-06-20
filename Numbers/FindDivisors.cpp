#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    // since the divisors occur in pairs, it is enough to traverse till sqrt(n)
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0) // check the divisibility
        {
            if(n/i==i) // if same number appears in the pair, for example for n =100, the number 10 occurs twice. It is enough to print
            // it once
                cout<<i<<" ";
            else // print the divisors
                cout<<i<<" "<<n/i<<" ";
        }
    }
   // The TC of the above algorithm is O( √n)
    return 0;
}
