/*
Implementation of Next Greater Element problem using stack

Given an array, print the Next Greater Element (NGE) for every element. 
The Next greater Element for an element x is the first greater element on 
the right side of x in array. Elements for which no greater element exist, 
consider next greater element as -1.

For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.

Element --> NGE

4 --> 5
5 --> 25
2 --> 25
25 --> -1    */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> v)
{
    vector<int> nge(v.size());
    stack<int> stk;
    for(int i=0;i<v.size(); i++)
    {
        while(!stk.empty() && v[i] > v[stk.top()])
		{
            nge[stk.top()]=i;
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty())
    {
        nge[stk.top()]=-1;
            stk.pop();
    }
    return nge;
}

int main() 
{
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i=0;i<n;i++)
        cin >> v[i];
        
    vector<int> nge= NGE(v);
    
    for(int i=0; i<n; i++)
        cout<< v[i] << " " << (nge[i]== -1 ? -1 : v[nge[i]]) << endl;
        
    return 0;
}

/*

Test case 1:

Sample Input

4
4 5 2 25

Sample Output

4 5
5 25
2 25
25 -1

Test case 2:

Sample Input

4
13 7 6 12

Sample Output

13 -1
7 12
6 12
12 -1

Time Complexity: O(n)
Space Complexity: O(n)
*/