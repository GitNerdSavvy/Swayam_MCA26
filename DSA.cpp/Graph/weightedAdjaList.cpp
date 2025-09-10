#include<bits/stdc++.h>
using namespace std;
vector<list<pair<int,int>>>wug;
int v;
unordered_set<int>visited;
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
bool dfs(int curr,int end){
    if(curr==end) return true;
    visited.insert(curr);
    for(auto it : wug[curr]){
        if(!visited.count(it.first)){
            bool res = dfs(it.first,end);
            if(res) return true;
        }

    }
    return false;
}
bool anypath(int s,int d){
    return dfs(s,d);
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
    cout<<anypath(s,d);

}
