/*
Problem Statement:
Bastin once had trouble finding the numbers in a string. The numbers are distributed in a string across various test cases.
There are various numbers in each test case you need to find the number in each test case. Each test case has various numbers
in sequence. You need to find only those numbers which do not contain 9. For eg, if the string contains "hello this is alpha
5051 and 9475".You will extract 5051 and not 9475. You need only those numbers which are consecutive and you need to help him
find the numbers. 

For example:

Input:
1
This is alpha 5057 and 97
Output:
5057
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int T;
	string str;
	cin>>T;
	cin.ignore();

	while(T--)
	{
	    string num="", res="";
	    int n9=0;
	    getline(cin, str);
	    int n = str.length();
	    for(int i=0;i<n;i++)
	    {
	        n9=0;
	        num = "";
	        while(str[i]>='0' && str[i]<='9')
	        {
	            if(str[i]=='9')
	                n9=1;
	            num = num + str[i];
	            i++;

	        }
	        if(!n9 && num!="")
	        {
	            long long int val = stoll(num);
	            long long int b=-1;

	            if(res!="")
	                b = stoll(res);

	            if(val>b)
	            {
	                res = num;
	            }

	        }

	    }
	    if(res=="")
	        cout<<-1;
	    cout<<res<<endl;

	}
	return 0;
}
