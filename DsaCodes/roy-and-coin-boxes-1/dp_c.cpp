// Problem: C - Vacation
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_c
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
vector<vector<int>>grid;
int dp[100005][5];
int func(int i,int j){
	if(i==n) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int ans=0;
	if(j==0){
		ans=max(grid[i][j]+func(i+1,j+1),grid[i][j]+func(i+1,j+2));
	}else if(j==1){
		ans=max(grid[i][j]+func(i+1,j-1),grid[i][j]+func(i+1,j+1));
	}else{
		ans=max(grid[i][j]+func(i+1,j-1),grid[i][j]+func(i+1,j-2));
	}
	return dp[i][j]=ans;
}
 
 
 void solve() {
    cin>>n;
    grid.assign(n,vector<int>(3,0));
    f(i,0,n){
    	f(j,0,3){
    		cin>>grid[i][j];
    	}
    }
    memset(dp,-1,sizeof dp);
    int ans=0;
    for(int col=0;col<3;col++){
    	ans=max(ans,func(0,col));
    }
    cout<<ans<<"\n";
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