// Problem: Coin Combinations II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1636
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

#define MOD 1000000007
 int n;
 int dp[1000005];
 vector<int>arr;
 int func(int x,int i){
 	if(x==0) return 1;
 	if(x<0) return 0;
 	if(dp[x] != -1) return dp[x];
 	ll ans=0;
 	for(int j=i;j<n;j++){
 	if(x-arr[j]>=0){
 		ans+=func(x-arr[j],j);
 		if(ans>=MOD) ans-=MOD;
 		}
 	}
 	return dp[x]= ans;
 }
 void solve() {
 	int x;
    cin>>n>>x;
    arr.resize(n);
    f(i,0,n) cin>>arr[i];
    memset(dp,-1,sizeof dp);
    cout<< func(x,0) nline;

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