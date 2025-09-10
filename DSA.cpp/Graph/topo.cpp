#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> topo;
vector<int> vis;

void dfs(int node)
{
    vis[node] = 1;
    for (auto it : graph[node])
    {
        if (!vis[it])
        {
            dfs(it);
        }
    }
    topo.push_back(node);
}
int main()
{
    int v, e;
    cin >> v >> e;
    graph.resize(v + 1);
    vis.assign(v + 1, 0);
    topo.resize(v);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        // graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for (int i = 0; i < v; i++)
    {
        cout << topo[i] << " ";
    }
}