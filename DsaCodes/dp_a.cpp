// Problem: A - Frog 1
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_a
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
int n;
int dp[100005];
int func(vector<int>& arr,int i){
	if(i==n-1) return 0;
	if(dp[i]!=-1) return dp[i];
	int n1=1e5;
	if(i<n-1){
		n1=abs(arr[i+1]-arr[i])+func(arr,i+1);
	}
	
	int n2=1e5;
	if(i<n-2){
		 n2=abs(arr[i+2]-arr[i])+func(arr,i+2);
	}
	
	
	return dp[i]= min(n1,n2);
}
 
 
 void solve() {
    
    cin>>n;
    vector<int>arr(n);
    f(i,0,n) cin>>arr[i];
    memset(dp,-1,sizeof dp);
    cout<<func(arr,0);

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