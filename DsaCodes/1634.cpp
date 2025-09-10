// Problem: Minimizing Coins
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1634
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

int n;
vector<int> arr;
vector<int> dp;

int func(int x) {
    if (x == 0) return 0;
    if (x < 0) return 1e9;
    if (dp[x] != -1) return dp[x];

    int ans = 1e9;
    for (int c : arr) {
        ans = min(ans, 1 + func(x - c));
    }
    return dp[x] = ans;
}

void solve() {
    int x;
    cin >> n >> x;
    arr.resize(n);
    f(i, 0, n) cin >> arr[i];

    dp.assign(x + 1, -1);
    int ans = func(x);
    if (ans >= 1e9) cout << -1;
    else cout << ans;
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