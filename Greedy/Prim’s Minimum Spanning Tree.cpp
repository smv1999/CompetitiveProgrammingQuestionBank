// Program to calculate Minimum Spanning Tree using Prim's algorithm in C++.
#include <iostream>
#include <conio.h>
#define ROW 7
#define COL 7
#define INFINITY 5000
using namespace std;
class MST
{
    int graph[ROW][COL], nodes, mini;

public:
    MST();
    void createGraph();
    void primsAlgo();
};

MST ::MST()
{
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            graph[i][j] = 0;
}

void MST ::createGraph()
{
    int i, j;
    cout << "Enter Total Nodes : ";
    cin >> nodes;
    cout << "\nEnter Adjacency Matrix : \n";
    for (i = 0; i < nodes; i++)
        for (j = 0; j < nodes; j++)
            cin >> graph[i][j];

    for (j = 0; j < nodes; j++)
    {
        if (graph[i][j] == 0)
            graph[i][j] = INFINITY;
    }
}

void MST ::primsAlgo()
{
    int selected[ROW], i, j, nos_of_edges, x, y;

    for (i = 0; i < nodes; i++)
        selected[i] = false;

    selected[0] = true;
    nos_of_edges = 0;

    while (nos_of_edges < nodes - 1)
    {
        mini = INFINITY;

        for (i = 0; i < nodes; i++)
        {
            if (selected[i] == true)
            {
                for (j = 0; j < nodes; j++)
                {
                    if (selected[j] == false)
                    {
                        if (mini > graph[i][j])
                        {
                            mini = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = true;
        cout << "\n"
             << x + 1 << " --> " << y + 1;
        nos_of_edges = nos_of_edges + 1;
    }
}

int main()
{
    MST a;
    cout << "\nPrims Algorithm to find Minimum Spanning Tree\n";
    a.createGraph();
    a.primsAlgo();
    getch();
    return 0;
}
