#include<bits/stdc++.h>
using namespace std;
vector<list<int>>uug;
int v;

void add(int s,int d,bool bi_d=true){
    uug[s].push_back(d);
    if(bi_d) uug[d].push_back(s);
}
void display(){
    for(int i=0;i<uug.size();i++){
        cout<<i<<"->";
        for(auto it:uug[i]){
            cout<<it<<" , ";
        }
        cout<<endl;
    }
}
int main(){
    cin>>v;
    uug.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add(s,d);
    }
    display();

}
