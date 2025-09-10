// Problem: Edit Distance
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1639
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


string s1,s2;
int dp[5005][5005];
 int func(int i,int j){
 	if(i==s1.size()) return s2.size()-j;
 	if(j==s2.size()) return s1.size()-i;
 	if(dp[i][j] != -1) return dp[i][j];
 	int ans=1e9;
 	if(s1[i]==s2[j]){
 		return ans=min(ans,func(i+1,j+1));
 	}
 	ans=min({1+func(i+1,j),1+func(i,j+1),1+func(i+1,j+1)});
 	return dp[i][j]= ans;
 }
 
 void solve() {
    
    cin>>s1>>s2;
    memset(dp,-1,sizeof dp);
    cout<<func(0,0);

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