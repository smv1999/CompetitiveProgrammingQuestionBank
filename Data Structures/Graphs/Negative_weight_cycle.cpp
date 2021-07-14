/*Program to detect whether a directed graph has negative cycle or not

We are given a directed graph. We need to detect whether the graph has 
a negative cycle or not. A negative cycle is one in which the overall 
sum of the cycle becomes negative.

In this program, Bellman Ford algorithm is used to detect negative cycle
in a graph.

Bellman Ford algorithm is a algorithm which help us to find the shortest 
path from a starting vertex to all other vertices of a weighted graph.

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include<string>
using namespace std;

//Define infinity as the maximum value of the integer
#define INF INT_MAX
#define ne 4

//Data structure to store a graph edge
struct Edge
{
	//edge from 'source' to 'dest' having a weight equal to 'weight'
	int source, dest, weight;
};

//This is a function to run the Bellman Ford algorithm
bool BellmanFord(vector<Edge> const &edges, int source)
{
	// cost[] stores shortest path information
	int cost[ne];

	//Initially, all vertices except the source vertex weight infinity
	fill_n(cost, ne, INF);
	cost[source] = 0;

	int u, v, w, k = ne;

	//Relaxation step (it will run 'V-1' times)
	while (--k)
	{
		for (Edge edge: edges)
		{
			// edge from 'u' to 'v' having weight 'w'
			u = edge.source;
			v = edge.dest;
			w = edge.weight;

			// if the cost to destination 'u' can be
			// shortened by taking edge 'u' -> 'v'
			if (cost[u] != INF && cost[u] + w < cost[v])
			{
				// update cost to the new lower value
				cost[v] = cost[u] + w;
			}
		}
	}

	// Run relaxation step once more for ne'th time to
	// check for negative-weight cycles
	vector<int> cycle;
	for (Edge edge: edges)
	{
		// edge from 'u' to 'v' having weight 'w'
		u = edge.source;
		v = edge.dest;
		w = edge.weight;

		// if the cost to destination 'u' can be
		// shortened by taking edge 'u' -> 'v'
        
		if (cost[u] != INF && cost[u] + w < cost[v]) {
			return true;
		}
	}

	return false;
}

int main()
{
	
	// given adjacency representation of the matrix
	int adjMatrix[ne][ne] =
	{
		
		{ 0,	INF, -2, INF },
		{ 4,	0,	-3, INF },
		{ INF, INF, 0,	2 },
		{ INF, -1, INF, 0 }
	};
	
	// create a vector to store graph edges
	vector<Edge> edges;

	for (int v = 0; v < ne; v++)
	{
		for (int u = 0; u < ne; u++)
		{
			if (adjMatrix[v][u] && adjMatrix[v][u] != INF) {
				edges.push_back({v, u, adjMatrix[v][u]});
			}
		}
	}

	
	int i;
	for (i = 0; i < ne; i++)
	{
		// run Bellman Ford algorithm from each vertex as the source
		// and check for any negative-weight cycle
		if (BellmanFord(edges, i))
		{
			cout << "Negative-weight cycle is found!";
			break;
		}
	}
	
	//condition if the graph doesn't contain negative cycle
	if (i == ne)	
		cout << "Negative-weight cycle doesn't exist.";

	return 0;
}

/*

Example Input -

Adjacency Matrix:

	{ 0,   1, INF,  INF, INF},
	{INF,   0, 	2, INF, INF},
	{INF, INF,  0,	3, INF},
	{INF, INF, INF, 0,  -3}
	{INF, -3, INF, INF, 0}
	
Example Output -

Negative-weight cycle is found!

Example Input -

Adjacency Matrix:

	{ 0,   4, INF,  5},
	{INF,   0, INF, INF},
	{INF, -10,  0, INF},
	{INF, INF, 3, 0}
	
Example Output -

Negative-weight cycle doesn't exist.*/