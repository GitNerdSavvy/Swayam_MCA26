#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ll n,m;
    cin>>n>>m;
    // if(n>m) swap(n,m);
    // vector<int>arr;
    // for(int i=1;i<100001;i++){
    //     if(n%i==0 && m%i==0){
    //         arr.push_back(i);
    //     }
    // }
    // int x=arr.size();
    // vector<bool>ans(x+1,true);
    // for(int i=2;i<=x;i++){
    //     if(ans[i]){
    //         for(int j=i*2;j<=x;j+=i){
    //             ans[j]=false;
    //         }
    //     }
    // }
    // int res=0;
    // for(int i=1;i<x;i++){
    //     if(ans[i]) {
    //         cout<<i<<" ";
    //         res++;
    //     }
    // }
    // cout<<res;

    ll gc=__gcd(n,m);
    int ans=1;
    for(int i=2;i<=gc;i++){
        if(gc%i==0) ans++;
        while(gc%i==0){
            gc/=i;
        }
    }
    cout<<ans;
}
