// Problem: B - Looped Rope
// Contest: AtCoder - AtCoder Beginner Contest 422
// URL: https://atcoder.jp/contests/abc422/tasks/abc422_b
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
#define MOD 1000000007

  char grid[101][101];
 
 void solve() {
    int n,m;
    cin>>n>>m;
   
	cf(i,1,n){
		cf(j,1,m){
			cin>>grid[i][j];
		}
	}
	cf(i,1,n){
		cf(j,1,m){
			if(grid[i][j]=='#'){
				int cnt=0;
				if(grid[i+1][j]=='#') cnt++;
				if(grid[i-1][j]=='#') cnt++;
				if(grid[i][j-1]=='#') cnt++;
				if(grid[i][j+1]=='#') cnt++;
				if(cnt !=2 && cnt !=4){
					cout<<"No" nline
					return;
				}
			}
		}
	}
	cout<<"Yes" nline
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