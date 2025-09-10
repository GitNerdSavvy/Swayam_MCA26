// Problem: I - Coins
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_i
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


double dp[3005][3005];
 double func(vector<double>&p,int i,int head){
  
  if(head==0) return 1;
  if(i==-1) return 0;
  if(dp[i][head]> -0.9) return dp[i][head];
  return dp[i][head]= func(p,i-1,head-1)*p[i] + func(p,i-1,head)*(1-p[i]);
}
 
 void solve() {
   
    int n;
  cin>>n;
  vector<double>prob(n);
  for(int i=0;i<n;i++){
    cin>>prob[i];
  }
  memset(dp, -1 ,sizeof dp);
  int h=(n+1)/2;
  double ans=func(prob,n-1,h);
  cout<<fixed<<setprecision(9)<<ans;
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin>>t;
	// while(t--){
        solve();
	// }
	return 0;
}