/*  ' Is Graph Bipartite ' problem from Leetcode

    A graph is bipartite if the nodes can be partitioned into two independent sets A and B
    such that every edge in the graph connects a node in set A and a node in set B.

    The main function is predefined. Here is the code to the question.
*/


class Solution {
public:

    vector<int> color;
    bool dfs(int node, vector<vector<int>> &graph){
        for(auto child: graph[node]){
            if(color[child] != -1){
                if(color[child] == color[node])
                    return false;
                continue;
            }
            color[child] = (color[node] + 1)%2;
            if(!dfs(child, graph)) 
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color = vector<int> (n, -1);
        for(int node=0; node<n; node++){
            if(color[node]==-1){
                color[node] = 0;
                if(!dfs(node, graph)) return false;
            }
        }
        return true;
    }
};

/*
    Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
    Output: false
*/