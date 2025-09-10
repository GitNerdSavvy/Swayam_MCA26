// Problem: Longest Common Subsequence
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3403
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
 
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define nline <<"\n";

 int n,m;
 vector<int>arr1,arr2;
 vector<int>res;
 int dp[1005][1005];
 int func(int i,int j){
 	if(i==n || j==m) return 0;
 	if(dp[i][j] != -1) return dp[i][j];
 	int ans=0;
 	if(arr1[i]==arr2[j]){
 		ans=max(ans,1+func(i+1,j+1));
 	}else{
 		ans=max({ans,func(i+1,j),func(i,j+1)});
 	}
 	return dp[i][j]= ans;
 }
 void buildLCS(int i, int j) {
    if (i == n || j == m) return;
    if (arr1[i] == arr2[j]) {
        res.push_back(arr1[i]);
        buildLCS(i+1, j+1);
    } else {
        if (dp[i+1][j] >= dp[i][j+1]) {
            buildLCS(i+1, j);
        } else {
            buildLCS(i, j+1);
        }
    }
}
 void solve() {
   
    cin>>n>>m;
    arr1.resize(n);
    arr2.resize(m);
    f(i,0,n) cin>>arr1[i];
    f(i,0,m) cin>>arr2[i];
    memset(dp,-1,sizeof dp);
    cout<<func(0,0) nline
    buildLCS(0,0);
    f(i,0,res.size()) cout<<res[i]<<" ";

}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // int t;
   // cin>>t;
	//while(t--){
        solve();
	//}
	return 0;
}