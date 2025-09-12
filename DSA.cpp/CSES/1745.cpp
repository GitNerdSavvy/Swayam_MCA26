// Problem: Money Sums
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1745
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
si res;
int dp[105][100005];
 int func(int i, int csum){
 	if(i>=n) {
 		res.insert(csum);
 		return 0;
 	}
 	if(dp[i][csum] != -1) return dp[i][csum];
 	return dp[i][csum]=func(i+1,csum) || func(i+1,csum+arr[i]);
 	
 }
 void solve() {
    cin>>n;
    arr.resize(n);
    f(i,0,n) cin>>arr[i];
    memset(dp,-1,sizeof dp);
    func(0,0);
    res.erase(0);
    cout<<res.size() nline;
    for(auto it:res) cout<<it<<" ";
    

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