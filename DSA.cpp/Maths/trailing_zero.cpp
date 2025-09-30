#include<bits/stdc++.h>
using namespace std;

int power(int n,int p){
    int g=p;
    int ans=0;
    while(g<=n){
        ans+=n/g;
        g*=p;
    }
    return ans;
}
int trailing_zeros(int n){
    return power(n,5);
}
int main(){
    int n;
    cin>>n;
    cout<<trailing_zeros(n);
}