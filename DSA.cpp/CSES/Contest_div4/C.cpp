// Problem: C. Pacer
// Contest: Codeforces - Codeforces Round 1050 (Div. 4)
// URL: https://codeforces.com/contest/2148/problem/C
// Memory Limit: 256 MB
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

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n+1), b(n+1);
    for (int i=1;i<=n;i++) cin >> a[i] >> b[i];

    ll ans = 0;
    ll pt = 0, ps = 0;

    for (int i=1;i<=n;i++) {
        ll len = a[i] - pt;
        if (ps == b[i]) {
            ans += len - (len % 2);
        } else {
            if (len % 2 == 1) ans += len;
            else ans += len - 1;
        }
        pt = a[i];
        ps = b[i];
    }

    ll len = m - pt;
    ans += len;

    cout << ans << '\n';
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
