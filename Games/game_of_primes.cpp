/*
Game of Primes

input
1
30
3

output
19

We need to find such as number within the given range that it should be a prime number 
and also a happy number.

*/
#include<iostream>
#include<math.h>
using namespace std;
bool isHappy(int n)
{
    int sum =0;
    while(n>0)
    {
        sum = sum + (n%10) * (n%10);
        n = n / 10;
    }
    if(sum==1)
    {
        return true;
    }
    else if(sum==4) {
        return false;
    }
    isHappy(sum);
}
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
    int a,b,count=0,n;
    cin>>a>>b>>n;
    for(int i=a;i<=b;i++)
    {
        if(isPrime(i) && isHappy(i))
        {
            count++;
        }
        if(count == n)
        {
            cout<<i;
            break;
        }
       
    }
     if(count < n)
        {
            cout<<"No number is present at this index.";
        }
    return 0;
}
