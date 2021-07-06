/* There is an undirected star graph consisting of n nodes labeled from 1 to n.
 A star graph is an undirected graph that has n nodes in which one is center node and  has exactly n - 1 edges.

 Given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi.
 Return the center of the given star graph.
    4
    |
    2
   / \
  1   3 
  
 Here 2 is the answer.
 
 Approach: Store the nodes in vector that are connected to partciular node, if size of that vector equals to nodes-1 then 
 print it is the centre. */

#include <bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>& edges)
{
        int n=edges.size()+1;
        
        vector<int>l[n+1];
        
        // Store the destintaion edges into source node vector
        for(int i=0;i<edges.size();i++)
        {
                l[edges[i][0]].push_back(edges[i][1]);
                l[edges[i][1]].push_back(edges[i][0]);
        }
         
        // Check if vector size is equal to nodes-1, to find the center
        int center;
        for(int i=0;i<=n;i++)
        {
            if(l[i].size()==n-1)
                center=i;
        }
        return center;
}

int main()
{
    int src,dest,no_of_edges;
    cout<<"Enter number of edges"<<endl;
    cin>>no_of_edges;
    vector<vector<int>>edges;
    
    for(int i=0;i<no_of_edges;i++)
    {
        vector<int>temp;
        
        cout<<"Enter source of edge"<<endl;
        cin>>src;
        temp.push_back(src);
        cout<<"Enter destination of edge"<<endl;
        cin>>dest;
        temp.push_back(dest);
        
        edges.push_back(temp);
    }
    cout<<"Center Of Star Graph : ";
    cout<<(findCenter(edges));
    return 0;
}


/* 
INPUT:
Enter number of edges
3
Enter source of edge
1
Enter destination of edge
2
Enter source of edge
2
Enter destination of edge
3
Enter source of edge
4
Enter destination of edge
2
OUTPUT:
Center Of Star Graph : 2

Time Complexity: O(no_of_edges)
Space Complexity: O(no_of_edges)
*/