// Problem: Two Sets II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1093
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
int dp[505][200005];
 int func(int i,int ans){
 	if(ans<0) return 0;
 	if(i>n) return ans==0;
 	if(dp[i][ans] != -1) return dp[i][ans];
 	int res=0;
 	res= func(1+i,ans-i)%MOD + func(1+i,ans)%MOD;
 	
 	return dp[i][ans] = res;
 }
 
 void solve() {
    
    cin>>n;
    int ans=n*(n+1)/2;
    if(ans%2==1){
    	cout<<0 nline
    	return;
    }
    memset(dp, -1, sizeof dp);
    cout<< (func(1,ans/2))/2 nline

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