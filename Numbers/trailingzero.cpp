
#include <iostream>

using namespace std;
int trailingZeroes(int n) {
        int p=5,sum=0;
        while((n/p)>0)
        {
            sum+=(n/p);
            p=p*5;
        }
        return sum;
    }
int main()
{int n=0;
   
 int total=0;
   cout<<"the number of trailing zeroes in n!\n";
   cout<<"Enter the number\t=\t";cin>>n;

 total=trailingZeroes(n);
 cout<<"\nnumber of zeroes in "<<n<<"!\t=\t"<<total;
    return 0;
}
