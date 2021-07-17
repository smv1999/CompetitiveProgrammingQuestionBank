/*
Union of the two arrays can be defined as the set containing distinct elements from both the arrays.
If there are repetitions, then only one occurrence of element should be considered in the union.
The final count should be printed.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        set<int>s;
        for (int i = 0; i < n; i++)
        s.insert(a[i]);
        
        for (int i = 0; i < m; i++)
        s.insert(b[i]);			//duplicates will not be added, property of sets
        
        return s.size();
    }
};


int main() {
	//enter number of test cases.
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    //accept size of both the arrays
	    cin >> n >> m;
	    int a[n], b[m];
	   
	   //accept the arrays
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	       
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;       //count is displayed
	    
	}
	
	return 0;
}  
