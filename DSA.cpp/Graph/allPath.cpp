#include<bits/stdc++.h>
using namespace std;
vector<list<pair<int,int>>>wug;
int v;
unordered_set<int>visited;
vector<vector<int>>res;
void add(int s,int d,int wt,bool bi_d=true){
    wug[s].push_back({d,wt});
    if(bi_d) wug[d].push_back({s,wt});
}
void display(){
    for(int i=0;i<wug.size();i++){
        cout<<i<<"->";
        for(auto it:wug[i]){
            cout<<"( " <<it.first<<" , "<<it.second<<" ) , ";
        }
        cout<<endl;
    }
}
void dfs(int curr,int end,vector<int> &path){
    if(curr==end) {
        path.push_back(curr);
        res.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for(auto it : wug[curr]){
        if(!visited.count(it.first)){
            dfs(it.first,end,path);
           
        }

    }
   path.pop_back();
   visited.erase(curr);
   return;
}
void allpath(int s,int d){
    vector<int>path;
     dfs(s,d,path);
}
int main(){
    cin>>v;
    wug.resize(v,list<pair<int,int>>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add(s,d,wt);
    }
    // display();
    int s,d;
    cin>>s>>d;
   allpath(s,d);
   for(auto p : res){
    for(int el : p){
        cout<<el<<" ";
    }
    cout<<endl;
   }

}
