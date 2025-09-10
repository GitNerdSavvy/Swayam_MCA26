// Problem: Removing Digits
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1637
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


int dp[1000005];
int fil(int num){
	int mx=0;
	while(num>0){
		int t=num%10;
		mx=max(mx,t);
		num/=10;
	}
	// cout<<mx nline
	return mx;
}

int func(int n){
	// if(n==0) return 0;
	if(n<10) return 1;
	if(dp[n] != -1) return dp[n];
	int ans=1e9;
	ans=1+func(n-fil(n));
	
	return dp[n]= ans;
	
}
 
 
 void solve() {
    int n;
    cin>>n;
    memset(dp,-1, sizeof dp);
    cout<<func(n);

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