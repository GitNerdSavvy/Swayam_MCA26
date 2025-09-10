#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<int>vis;

void dfs(int node,int cnt){
    cout<<node<<endl;
    vis[node]=cnt;
    for(auto it:graph[node]){ 
        if(!vis[it]){
            dfs(it,cnt);
        }
    }

}


int main(){
    int v,e;
    cin>>v>>e;
    graph.resize(v+1);
    vis.assign(v+1,0);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int count=0;
    for(int i=1;i<=v;i++){
        if(!vis[i]){
            count++;
            dfs(i,count);
        }
    }
    int arr[count+1];
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=v;i++){
        arr[vis[i]]++;
    }

    long long ans=0;
    long long sum=0;
    for(int i=1;i<=count;i++){
        ans+=1ll*arr[i]*sum;
        sum+=arr[i];
    }
    cout<<ans;
}