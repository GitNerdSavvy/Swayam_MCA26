#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> parent, size, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }
        else
        {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};
int main()
{
    DisjointSet ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.find(3) == ds.find(7))
        cout << "Same component\n";
    else
        cout << "Different components\n";

    ds.unionBySize(3, 7);

    if (ds.find(3) == ds.find(7))
        cout << "Same component\n";
    else
        cout << "Different components\n";

    return 0;
}