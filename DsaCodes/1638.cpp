// Problem: Grid Paths I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1638
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


const int MOD = 1e9 + 7;

 int n,m;
 vector<vector<char>>grid;
 int dp[1005][1005];
 
 int func(int i,int j){
 	 if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0 || grid[i][j]=='*')
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]= (func(i - 1, j) + func(i, j - 1))%MOD ;
        return dp[i][j];
 	
 }
 void solve() {
    cin>>n;
    m=n;
    grid.assign(n,vector<char>(m,'.'));
    f(i,0,n){
    	f(j,0,m){
    		cin>>grid[i][j];
    	}
    }
    if(grid[0][0]=='*' || grid[n-1][m-1]=='*'){
    	cout<<0;
    	return;
    }
    memset(dp,-1,sizeof dp);
    cout<<func(n-1,m-1);

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