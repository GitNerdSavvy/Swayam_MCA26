// Problem: Bit Strings
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1617
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
#define out(asy) cout<<asy nline
#define mod 1000000007

 int power(int a, int b, int m) {
    int ans = 1;
    a = a % m;
    while (b > 0) {
        if (b & 1)
            ans = (1LL * ans * a) % m;
        a = (1LL * a * a) % m;
        b >>= 1;
    }
    return ans;
}
 
 void solve() {
    int n;
    cin>>n;
    ll ans=power(2,n,mod)%mod;
    out(ans)

}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}
