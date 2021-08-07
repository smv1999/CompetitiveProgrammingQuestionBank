/*
Implementation of Bridge edge in Graph problem

Problem statement: 
Given an undirected graph of V vertices and E edges and another edge (c-d), the task is to 
find if the given edge is a bridge in graph, i.e., removing the edge disconnects the graph.

Link to the problem: https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:

    void dfs( vector<int> adj[],vector<int>&v,int i)
    {
        //marking visited
        v[i]=1; 

        //traversing adjacent node
        for(auto x:adj[i]) 
        {
            if(!v[x])
                dfs(adj,v,x);

        }

    }

    bool connected(vector<int>adj[],int n,int c,int d)
    {
        vector<int>v(n,0);

        // dfs from edge c
        dfs(adj,v,c); 

        //if edge d is not visited means not connected
        if(v[d]==0) 
            return false;

        return true;

    }

    //Function to find if the given edge is a bridge in graph.
    int isBridge(int n, vector<int>adj[], int c, int d) 
    {
        //if graph is not connected
        if(!connected(adj,n,c,d)) 
            return 0;

        else
        {
            //removing edge c and d
            adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
            adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());

            //if connected means no bridge
            if(connected(adj,n,c,d)) 
                return 0;
            else
                return 1;
        }

    }
};

// Driver Code Starts
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }

        int c,d;
        cin>>c>>d;

        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


/*
Time Complexity : O(V+E)
Space Complexity : O(V)

Input:
t=1
V=4 E=3
0 1
1 2
2 3
c=1  d=2

Output: 1

Explanation:
From the graph, we can clearly see that
removing the edge 1-2 will result in 
disconnection of the graph. So, it is 
a bridge Edge and thus the Output 1.

*/ 
