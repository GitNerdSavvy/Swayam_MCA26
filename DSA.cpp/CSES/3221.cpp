// Problem: Sliding Window Minimum
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3221
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
 
#define f(i,s,e) for(long long i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define nline <<"\n";
#define out(asy) cout<<asy nline
#define MOD 1000000007

 
void solve() {
    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    
    vll arr(n);
    arr[0]=x;
    f(i,1,n) arr[i]=(arr[i-1]*a + b) % c;
    
    vll res;
    deque<ll> dq;
    ll h = 0;
    
    while(h < n){
        while(!dq.empty() && arr[dq.back()] >= arr[h])
            dq.pop_back();
        
        dq.pb(h);
        
        while(!dq.empty() && dq.front() <= h - k)
            dq.pop_front();
        
        if(h >= k-1)
            res.pb(arr[dq.front()]);
        
        h++;
    }
    
    ll ans = 0;
    f(i,0,res.size()) ans ^= res[i];
    out(ans);
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}