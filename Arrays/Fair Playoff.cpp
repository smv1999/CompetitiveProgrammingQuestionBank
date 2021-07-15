/* Example:

Input:
4
3 7 9 5
4 5 6 9
5 3 8 1
6 5 3 2

Output:
YES
NO
YES
NO
*/

#include<iostream>
using namespace std;

int main()
{
	long int T;
	cin>>T;
	
	while(T--)
	{
		int s[4], i, f1 = 0, f2 = 0,sm = 0, no = 0, yes = 0;
		for(i = 0; i < 4; i++)
			cin>>s[i];
			
		if(s[0] > s[1])
			f1 = s[0];
			
		else
			f1 = s[1];
			
		if(s[2] > s[3])
			f2 = s[2];
			
		else
			f2 = s[3];
			
			
		if(f2 - f1 > 0)
			sm = f1;
		else
			sm = f2;
			
		
		for(i = 0; i < 4; i++)
		{
			if(s[i] > sm)
				yes++;
			else
				no++;
		}
		if(yes == 1)
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}
	return 0;
}