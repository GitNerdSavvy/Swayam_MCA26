// Problem: E - Knapsack 2
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

ll dp[105][100005];
ll func(vector<int>&wts,vector<ll>&value,int i,ll capacity){
	if(i==wts.size()) return 0;
	if(dp[i][capacity] != -1) return dp[i][capacity];
	ll ans=LLONG_MIN;
	ans=max(ans,func(wts,value,i+1,capacity));
	
	if(wts[i] <= capacity){
		ans=max(ans,value[i]+func(wts,value,i+1,capacity-wts[i]));
	}
	return dp[i][capacity]= ans;
}

 
 
 void solve() {
    int n;
    cin>>n;
    ll capacity;
    cin>>capacity;
    vector<int>wts(n);
    vector<ll>value(n);
    for(int i=0;i<n;i++){
    	int a;
    	ll b;
    	cin>>a>>b;
    	wts[i]=a;
    	value[i]=b;
    }
    memset(dp,-1, sizeof dp);
    cout<<func(wts,value,0,capacity);

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