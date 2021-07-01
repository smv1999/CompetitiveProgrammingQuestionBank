// Program to calculate Minimum Spanning Tree using Kruskal's algorithm in C++.
// Undirected graph is taken in consideration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    // V = Number of vertices, E = Number of edges
    int V, E;
    struct Edge *edge;
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    g->V = V;
    g->E = E;
    g->edge = (struct Edge *)malloc(g->E * sizeof(struct Edge));

    return g;
}

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int comp(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight > b1->weight;
}

// The function to construct MST
void MST(struct Graph *g)
{
    int V = g->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;

    qsort(g->edge, g->E, sizeof(g->edge[0]), comp);

    struct subset *subsets = (struct subset *)malloc(V * sizeof(struct subset));

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges = V-1
    while (e < V - 1)
    {
        struct Edge next_edge = g->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    cout << "Edges in the constructed MST\n";
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
               result[i].weight);
    return;
}

// Driver program
int main()
{
    /* This graph is taken for consideration.
         22
     0--------1
     | \      |
    16|   \5   |15
     |      \ |
     2--------3
        4       */
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    struct Graph *g = createGraph(V, E);

    // add edge 0-1
    g->edge[0].src = 0;
    g->edge[0].dest = 1;
    g->edge[0].weight = 22;

    // add edge 0-2
    g->edge[1].src = 0;
    g->edge[1].dest = 2;
    g->edge[1].weight = 16;

    // add edge 0-3
    g->edge[2].src = 0;
    g->edge[2].dest = 3;
    g->edge[2].weight = 5;

    // add edge 1-3
    g->edge[3].src = 1;
    g->edge[3].dest = 3;
    g->edge[3].weight = 15;

    // add edge 2-3
    g->edge[4].src = 2;
    g->edge[4].dest = 3;
    g->edge[4].weight = 4;

    MST(g);
    return 0;
}