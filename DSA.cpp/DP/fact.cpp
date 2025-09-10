#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
int fact(int n){
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=(i*dp[i-1]);
    }
    return dp[n]%MOD;
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
}