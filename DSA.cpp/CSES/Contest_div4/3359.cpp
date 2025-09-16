// Problem: Minimal Grid Path
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3359
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
 vector<vector<char>>grid;
 vector<string>res;
 int func(int i,int j,string ans){
 	if(i==n && j==n){
 		res.push_back(ans);
 		return 0;
 	}
 	if(i<n-1 && j<n-1){
 		return func(i+1,j,ans+grid[i][j]) || func(i,j+1,ans+grid[i][j]);
 	}else if(i<n-1){
 		return func(i,j+1,ans+grid[i][j]);
 	}else{
 		return func(i+1,j,ans+grid[i][j]);
 	}
 	
 }
 void solve() {
    cin>>n;
    grid.resize(n,vector<char>(n));
    f(i,0,n){
    	f(j,0,n){
    		cin>>grid[i][j];
    	}
    }
    func(0,0,"");
    sort(res.begin(),res.end());
    cout<<res[0] nline
    

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