#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>graph;
vector<int>dist;
int main(){
    cin>>n;
    graph.resize(n+1);
    dist.resize(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    
}