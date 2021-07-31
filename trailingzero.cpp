#include <iostream>
using namespace std;

int main() {
    int n=0;
	cout<<"trailing zero program\n";
	cout<<"Enter the number\t=\t";cin>>n;
	int p=5,cnt=0;
	while((n/p)>0)
	{
	    cnt=cnt+(n/p);
	    p=p*5;
	    
	}cout<<cnt<<endl;
	return 0;
}
