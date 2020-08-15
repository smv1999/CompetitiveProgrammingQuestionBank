/*
Consecutive Prime Sum
---------------------
Some prime numbers can be expressed as a sum of other consecutive prime numbers.

For example
5 = 2 + 3,
17 = 2 + 3 + 5 + 7,
41 = 2 + 3 + 5 + 7 + 11 + 13.
Your task is to find out how many prime numbers which satisfy this property are present in the range 3 to N subject to a constraint that summation should always start with number 2.
Write code to find out the number of prime numbers that satisfy the above-mentioned property in a given range.

Input Format: First line contains a number N

Output Format: Print the total number of all such prime numbers which are less than or equal to N.

Constraints: 2<N<=12,000,000,000
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
