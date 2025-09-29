// Problem: Exponentiation II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1712
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

 
 
 ll func(ll a,ll b,ll k){
 	ll ans=1;
 	a %= k;
 	while(b){
 		if(b%2){
 			ans=(ans*a)%k;
 		}
 			a=(a*a)%k;
 			b/=2;
 		
 	}
 	return ans;
 }
 
 void solve() {
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<func(a,func(b,c,MOD-1),MOD) nline;

}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int t;
   cin>>t;
	while(t--){
        solve();
	}
	return 0;
}