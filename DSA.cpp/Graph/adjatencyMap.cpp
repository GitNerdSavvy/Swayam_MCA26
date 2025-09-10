#include<bits/stdc++.h>
using namespace std;
vector<unordered_map<int,int>>wug;
int v;

void add(int s,int d,int wt,bool bi_d=true){
    wug[s][d]=wt;
    if(bi_d) wug[d][s]=wt;
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
int main(){
    cin>>v;
    wug.resize(v,unordered_map<int,int>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add(s,d,wt);
    }
    display();

}
