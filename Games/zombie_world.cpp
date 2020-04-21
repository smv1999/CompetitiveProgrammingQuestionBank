/*
Zombie World
------------

input 
10
2
4 9

output
YES

*/
#include<iostream>
using namespace std;
int bubbleSort(int a[],int n)
{  int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int b,n;
    cin>>b>>n;
    int z[n];
    for(int i=0;i<n;i++)
    {
        cin>>z[i];
    }
    bubbleSort(z,n);
    int flag = 1;
    for(int i=0;i<n;i++)
    {
        if(b<z[i])
        {
            flag =0;
            break;
        }
        b = b - (z[i]%2 + z[i]/2);
    }
    if(flag==1)
    cout<<"YES";
    else 
    cout<<"NO";
    return 0;
}
