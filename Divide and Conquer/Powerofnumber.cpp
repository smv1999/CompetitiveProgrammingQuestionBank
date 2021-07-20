
#include <iostream>

using namespace std;
int powerofnumber(int a,int n)
{int mid=0,c=0,b=0;
    if(n==1)
    {
        return a;
    }
    else
    {
        mid=n/2;
        b=powerofnumber(a,mid);
        c=b*b;
        if(n%2==0)
        {
           return c;
        }
        else
        {
            return a*c;
        }
    }
}
int main()
{ int num=0,ans=0,power=0;
    cout<<"Power of n element\n";
    cout<<"\nEnter the Number\t=\t";cin>>num;
    cout<<"Enter the power\t=\t";cin>>power;
   ans= powerofnumber(num,power);
   cout<<"Answer\t=\t"<<ans;
    return 0;
}
