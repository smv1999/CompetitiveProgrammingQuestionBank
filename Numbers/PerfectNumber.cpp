#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int n,sum=0;
    cin>>n;

    for(int i=1;i<sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
                sum+=i;
            else
                sum = sum + i + n/i;
        }
    }
    if(sum/2==n)
        cout<<"Perfect Number";
    else cout<<"Not a perfect number";
    return 0;
}
