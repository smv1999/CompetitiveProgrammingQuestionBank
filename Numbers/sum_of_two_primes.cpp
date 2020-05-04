/*
Sum of Two Primes

Write a program to find if a given number N can be expressed as a sum of prime numbers.

Input
5
20
12
23
34
16

Output
yes
yes
no
yes
yes

*/
#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n)
{
    if(n==1)
    return false;
    else{
        for(int i=2;i<=(int)sqrt(n);i++)
        {
            if(n%i == 0)
            return false;
        }
        return true;
    }
}
int main(int argc, char const *argv[])
{
    int t,n,count=0,flag=0;
    cin>>t;
    while (t--)
    {
        count = 0;
        flag = 0;
        cin>>n;
        int primelist[n];
        for(int i=2;i<=n;i++)
        {
            if(isPrime(i))
            {
                primelist[count]=i;
                count++;
            }
        }
        for(int i=0;i<count-1;i++)
        {
            for(int j=i+1;j<count;j++)
            {
                if(primelist[i]+primelist[j] == n)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if (flag)
        {
            cout<<"yes";
        }
        else{
            cout<<"no";
        }
    }
    
    return 0;
}

