#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    vector<int> adj_list[n + 1];

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        
    }

    for(int i=1; i<n+1; i++) {
        for(int j=0; j<adj_list[i].size(); j++)
            cout << adj_list[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
