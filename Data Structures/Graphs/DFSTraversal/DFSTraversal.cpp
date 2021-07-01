#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+3;
vector<int> g[N];
bool vis[N];

void dfs(int u)
{
    vis[u] = 1;
    for(int v:g[u])
    {
        if(vis[v]) continue;
        dfs(v);
    }
}

int main(int argc, char const *argv[])
{
    freopen("in.txt","r",stdin);
    int n,m,u,v;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u); // comment this in the case of directional edges
    }

    dfs(1); // starting node

    if(vis[6]) cout<<"Yes";
    else cout<<"No, we can't reach!";

    return 0;
}
