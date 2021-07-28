
/*Implementation of Maximum size rectangle binary sub-matrix with all 1s GFG

Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s. 

Link of the problem: https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MaximalRectangle 
{
	public:
    //In this function, we find next smallest element of each element
	vector<int> NSE(vector<int> v)
	{
		vector<int> nse(v.size(), v.size());
		stack<int> stk;
		for(int i=0; i<v.size(); i++)
		{
			while(!stk.empty() && v[stk.top()]>v[i])
			{
				nse[stk.top()]=i;
				stk.pop();
			}
			stk.push(i);
		}
		return nse;
	}
	
	//In this function, we will find previous smallest element of each element
	vector<int> PSE(vector<int> v)
	{
		vector<int> pse(v.size(), -1);
		stack<int> stk;
		for(int i=v.size()-1; i>=0; i--)
		{
			while(!stk.empty() && v[stk.top()]>v[i])
			{
				pse[stk.top()]=i;		
				stk.pop();
			}
			stk.push(i);
		}
		return pse;
	}
    
    int maximalRectangle(vector<vector<char>>& matrix) 
	{
        if(matrix.empty()) return {};
        
        int r= matrix.size();
        int c= matrix[0].size();
        
        if(r==0)
            return 0;
            
        if(r == 1 && c == 1) 
			return matrix[0][0] - '0';
        
        vector<vector<int>> v(r, vector<int>(c));
        
        for (int i = 0; i <r; i++) 
		{
        	for (int j = 0; j < c; j++)
                v[i][j]= matrix[i][j]=='1'?1: 0;
        }
        
        for (int i = 1; i < r; i++) 
		{
 
        	for (int j = 0; j < c; j++)
            	if (v[i][j])
                	v[i][j] += v[i - 1][j];
        }
		
        int area;
		for(int i=0; i<r ;i++)
		{
			vector<int> nse=NSE(v[i]);	
			vector<int> pse=PSE(v[i]);
		
			for(int j=0;j<c;j++)
				area = max(area, v[i][j]*(nse[j]-pse[j]-1));
		}
		return area;
    }
    
    
};

int main()
{	
	MaximalRectangle ob;

	int r,c;
	char value;
	cin>>r;
	cin>>c;
	vector<vector<char>> v(r);
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>value;
			v[i].push_back(value);
		}
	}
	int area = ob.maximalRectangle(v);
	cout<<area;
}

/*

Time Complexity: O(R x C)
Only one traversal of the matrix is required, so the time complexity is O(R X C)

Space Complexity: O(C)
Stack is required to store the columns, so so space complexity is O(C)

Example 1: 

Input:
	0 1 1 0
	1 1 1 1
	1 1 1 1
	1 1 0 0
	
Output : 8

Explanation : 
The largest rectangle with only 1's is from 
(1, 0) to (2, 3) which is
1 1 1 1
1 1 1 1 

Example 2:

Input:
	0 1 1
	1 1 1
	0 1 1 
	     
Output: 6

Explanation : 
The largest rectangle with only 1's is from 
(0, 1) to (2, 2) which is
1 1
1 1
1 1

*/