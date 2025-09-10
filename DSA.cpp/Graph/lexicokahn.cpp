#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> topo;
vector<int> indegree;

void kahn(int v,int e) {
    priority_queue<int> q;
    for (int i = 1; i <= v; i++) {
        if (indegree[i] == 0) {
            q.push(-i);
        }
    }
    while (!q.empty()) {
        int node = -q.top();
        q.pop();
        topo.push_back(node);
        for (auto it : graph[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    graph.resize(v + 1);
    indegree.assign(v + 1, 0);
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    kahn(v,e);
    for (int x : topo) {
        cout << x << " ";
    }
}
