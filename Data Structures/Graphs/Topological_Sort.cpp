/*
  Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering
  of vertices such that for every directed edge uv, vertex u comes before v in
  the ordering. Topological Sorting for a graph is not possible if the graph is
  not a DAG.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
stack<int> s;
bool *visited;

// Number of Test Cases (Vertices)
int n;

// function to Create and represent a graph by storing data.
void createGraph()
{
    int x, y;
    adjList.resize(n);

    for (int j = 0; j < n; j++)
    {
        cin >> x >> y;
        adjList[x].push_back(y);
    }
}

// A recursive function used by topoSortFun.
void topoSortFun(int i)
{
    visited[i] = true;
    for (int j = 0; j < adjList[i].size(); j++)
    {
        int key = adjList[i][j];
        if (!visited[key])
            topoSortFun(key);
    }
    s.push(i);
}

// The function to do Topological Sort. It uses recursive topoSortFun(). 
void topoSort()
{
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            topoSortFun(i);
    }
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    cout<<"Enter number of node you want to add: ";
    cin >> n;
    visited = new bool[n];
    cout<<"Enter nodes of graph: ";
    createGraph();
    topoSort();
    cout<<"Graph after topological sort: \n";
    display();
}

/*
Test Case:
Input:
Enter number of node you want to add: 6
Enter nodes of graph: 
5 2 
5 0 
4 0 
4 1 
2 3 
3 1 
Output:
Graph after topological sort: 
5 4 2 3 1 0 

Time Complexity: O(V + E) – where V is the number of vertices and E is the number of edges.
Space Complexity: O(V)
*/ 