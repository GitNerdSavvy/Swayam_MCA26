#include<bits/stdc++.h>
using namespace std;
int v,e;
vector<vector<pair<int,int>>>graph;
int dis[10100];
void bfs(int sc){
    deque<int>dq;
    for(int i=0;i<=v;i++){
        dis[i]=1e7;
    }
    dis[sc]=0;
    dq.push_back(sc);
    while(!dq.empty()){
        int x=dq.front();
        dq.pop_front();
        for(auto it:graph[x]){
            int neigh=it.first;
            int weight=it.second;
            if(dis[neigh]>dis[x]+weight){
                dis[neigh]=dis[x]+weight;
                if(weight==0){
                    dq.push_front(neigh);
                }else{
                    dq.push_back(neigh);
                }
            }
        }
    }
}
int main(){
    
    cin>>v>>e;
    for(int i=0;i<v;i++){
        int a,b,c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    int sc;
    cin>>sc;
    bfs(sc);
}