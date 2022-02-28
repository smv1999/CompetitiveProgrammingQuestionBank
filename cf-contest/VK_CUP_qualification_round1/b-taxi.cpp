#include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        long long unsigned int n,i,d,c1=0,c2=0,c3=0,count=0;
        cin>>n;
        while(n--)
        {
            cin>>d;
            if(d==1)
                c1++;
            else if(d==2)
                c2++;
            else if(d==3)
                c3++;
            else
                count++;
        }
        count+=c3;
        if(c1<=c3)
        {
            count+=c2/2 + c2%2;
        }
        else
        {
            c1-=c3;
            if(c1>=2*c2)
            {
                count+=c2;
                c1-=2*c2;
                count+=c1/4;
                if(c1%4!=0)
                    count++;
            }
            else
            {
                count+=c1/2+c1%2;
                c2-=c1/2+c1%2;
                count+=c2/2 + c2%2;
            }
        }
        cout<<count;
    }
