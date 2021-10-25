#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    int adj[n + 1][n + 1];

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << adj[i][j] << "\t\t";
        }
        cout << "\n";
    }
    return 0;
}
