// Problem: Sliding Window Mode
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3224
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
#define MOD 1000000007


 void solve() {
    int n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    f(i,0,n) cin>>arr[i];
    
    unordered_map<ll,ll>ump;
    map<ll,set<ll>>mp;
    vector<ll>res;
    ll l=0,h=0;
    
   while(h<n){
        ll x = arr[h++];
        ll fq = ump[x]++;
        if(fq > 0){
            mp[fq].erase(x);
            if(mp[fq].empty()) mp.erase(fq);
        }
        mp[fq+1].insert(x);
        
        if(h-l > k){
            ll y = arr[l++];
            ll f = ump[y]--;
            mp[f].erase(y);
            if(mp[f].empty()) mp.erase(f);
            if(ump[y] > 0) mp[ump[y]].insert(y);
        }
        
        if(h-l == k){
            auto it = prev(mp.end());
            res.pb(*it->second.begin());
        }
    }
	f(i,0,res.size()) cout<<res[i]<<" ";
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}