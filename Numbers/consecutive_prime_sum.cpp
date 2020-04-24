/*
Consecutive Prime Sum
---------------------

*/
#include<iostream>
#include<math.h>
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

bool binarySearch(int a[],int n,int k)
{
  int first = 0;
  int last = n-1;
  while(first <= last)
  {
    int mid = (first + last)/2;
    if(a[mid]>k)
    last = last -1;
    else if(a[mid]<k)
    first = first + 1;
    else if(a[mid]==k)
      return true;
  }
  return false;
}
int main(int argc, char const *argv[])
{
    int count = 0,n,sum=2,prime_count=0;
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
    for(int i=1;i<count;i++)
    {
        sum = sum + primelist[i];
        if(binarySearch(primelist,count,sum))
        {
            prime_count++;
        }
    }
    cout<<"Total number of all such prime numbers are:"<<prime_count;
    return 0;
}
