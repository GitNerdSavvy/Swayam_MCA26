// Problem: Mancunian and K-Ordered LCS
// Contest: HackerEarth
// URL: https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
// Memory Limit: 256 MB
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


template <class T>
void printv(vector<T> &v) { for (auto x : v) cout << x << " "; cout << "\n"; }
void printa(int arr[], int n) { for (int i = 0; i < n; i++) printf("%d%c", arr[i], i == n - 1 ? '\n' : ' '); }
 
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int n,m;
vector<ll>arr1(2005);
vector<ll>arr2(2005);
int dp[2005][2005][10];

int func(int i,int j,int k){
	if(n==i || m==j) return 0;
	if(dp[i][j][k]!=-1){
		return dp[i][j][k];
	}
	int res=0;
	if(arr1[i]==arr2[j]){
		res=1+ func(i+1,j+1,k);
	}else{
		if(k>0){
			res=1+func(i+1,j+1,k-1);
		}else{
			res=max(res,func(i+1,j,k));
			res=max(res,func(i,j+1,k));
		}
	}
	dp[i][j][k]=res;
	return res;
}
 
 void solve() {
 	int k;
	cin>>n>>m>>k;  
	f(i,0,n) cin>>arr1[i];
	f(i,0,m) cin>>arr2[i];
	memset(dp,-1,sizeof dp);
	cout<<func(0,0,k);  
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