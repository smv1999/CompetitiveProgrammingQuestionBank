/*
Boruvka’s Algorithm is a greedy algorithm used for finding Minimum Spanning Tree (MST) for
a connected, weighted, and undirected graph.
The goal of the algorithm is to connect “components” using the shortest or cheapest edge between
the components. It begins with all of the vertices considered as separate components.
Boruvka’s algorithm is parallel in nature. It operates in phases. In each phase, it selects
the cheapest edge from each component, adds all of these to the MST at once, and then contracts
each connected component into a single component.
We make use of a Union-Find data structure to keep track of the components.
This program takes a connected, weighted, and undirected graph as input and prints the total weight of edges in MST.
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)1e5 + 7;

//a structure which represents a weighted graph edge
struct edge {
    int v, u, cost;
};

//global declaration of number of nodes
int n;

//global declaration of number of edges
int m;

//global declaration of parent array
int p[N];

//Array to store the minimum or cheapest outgoing edge for each component of graph
int min_edge[N];

//Array to store all edges
edge g[N];

// Function to find root of a certain component for union find algorithm
int root(int v)
{
    if (p[v] == v)
        return v;

    return (p[v] = root(p[v]));
}

// Function to perform union two components
bool merge(int v, int u)
{
    v = root(v), u = root(u);
    if (v == u)
        return 0;

    p[v] = u;
    return 1;
}

// Function to initialize DSU
// Initially, all vertices are their own parents
void init_div()
{
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

//Main function to find MST using Boruvka's algorithm
void boruvkaAlgorithm()
{

    //Function call to initialize DSU
    init_div();

    // No. of components
    int cnt_cmp = n;

    //Weight of MST
    ll MSTweight = 0;

    // Keep combining components until all components are not combined into  a single MST.
    while (cnt_cmp > 1) {
        // Everytime initialize cheapest array to -1 as initially there is no cheapest edge
        for (int i = 1; i <= n; i++)
            min_edge[i] = -1;

        //Traverses through all edges to find the cheapest edge for each component
        for (int i = 1; i <= m; i++) {
            //If the nodes are in the same component then continue
            if (root(g[i].v) == root(g[i].u))
                continue;

            //Else take roots of 1st and 2nd components and check if current edge is cheapest edge
            int r_v = root(g[i].v);
            if (min_edge[r_v] == -1 || g[i].cost < g[min_edge[r_v]].cost) {
                min_edge[r_v] = i;
            }
            int r_u = root(g[i].u);
            if (min_edge[r_u] == -1 || g[i].cost < g[min_edge[r_v]].cost) {
                min_edge[r_u] = i;
            }
        }

        // Consider the above picked cheapest edges and add them
        // to MST
        for (int i = 1; i <= n; i++) {
            if (min_edge[i] != -1) {

                //If the two vertices that are connected with this edge
                //can be merged then add its weight to the answer,i.e MSTweight
                //and decrease the number of components by one
                if (merge(g[min_edge[i]].v, g[min_edge[i]].u)) {
                    MSTweight += g[min_edge[i]].cost;
                    cnt_cmp--;
                }
            }
        }
    }
    cout << "Total weight of Minimum Spanning Tree for the given graph: " << MSTweight << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Input number of nodes and edges" << endl;
    cin >> n >> m;

    cout << "Input source vertex, target vertex and weight for each edge" << endl;
    for (int i = 1; i <= m; i++) {
        cin >> g[i].v >> g[i].u >> g[i].cost;
    }

    boruvkaAlgorithm();

    return 0;
}

/*
INPUT:
Input number of nodes and edges                                                                                                                 
4 5                                                                                                                                             
Input source vertex, target vertex and weight for each edge                                                                                     
1 2 10                                                                                                                                          
2 3 15                                                                                                                                          
1 3 5                                                                                                                                          
4 2 2                                                                                                                                           
4 3 40 
OUTPUT:
Total weight of Minimum Spanning Tree for the given graph: 17

Time Complexity: O(E log V)
    E = Number of edges
    V = Number of vertices
Space Complexity: O(N)
*/