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
