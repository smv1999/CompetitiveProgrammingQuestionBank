/*
Write a Program to find the minimum number of powers (sum of all those numbers) that are 
required to form the given input number and print those numbers.

*/
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    int n = 20,count=0,flag=0;
    int powers[n],res=0,j,k;
    for(int i=1;i<=10;i++)
    {
       powers[count++]= pow(2,i);
    }
    for(j=0;j<count;j++)
    {
        for(k=j+1;k<count;k++)
        {
            if(powers[j]+powers[k] == n)
            {
                res+=2;
                flag = 1;
                break;
            }
            
        }
        if(flag==1)
            break;
    }
    cout<<"Count of numbers required = "<<res<<endl;
    cout<<"The powers of two are:"<<powers[j]<<" "<<powers[k];
    return 0;
}
