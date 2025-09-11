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
 vi arr;
 // vector<vector<int>> dp;
 // int func(int i,int sm){
 	// if(sm==0) return 1;
 	// if (i >= n || sm < 0) return 0;
 	// if(dp[i][sm] != -1) return dp[i][sm];
 	// ll take = func(i, sm - arr[i]);
    // ll skip = func(i + 1, sm);
// 
    // return dp[i][sm] = (take + skip) % MOD;
 // }
 void solve() {
    int sum;
    cin>>n>>sum;
    arr.resize(n);
    f(i,0,n) cin>>arr[i];
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
	for(int it:arr){
		cf(i,it,sum){
			dp[i]+=dp[i-it];
			if(dp[i]>=MOD) dp[i]-=MOD;
		}
	}
	cout<<dp[sum];
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