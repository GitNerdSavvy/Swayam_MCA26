// Problem: E. Hidden Knowledge of the Ancients
// Contest: Codeforces - Codeforces Round 1054 (Div. 3)
// URL: https://codeforces.com/contest/2149/problem/E
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

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795


vector<int> cmp(const vector<ll>& a) {
    int n = (int)a.size();
    vector<ll> ve = a;
    sort(all(ve));
    ve.erase(unique(all(ve)), ve.end());
    vector<int> res(n);
    f(i,0,n){
        res[i] = (int)(lower_bound(all(ve), a[i]) - ve.begin());
    }
    return res;
}


vector<int> compute_L(const vector<int>& a, int K) {
    int n = (int)a.size() - 1; 
    vector<int> L(n+1);
    unordered_map<int,int> fq;
    fq.reserve(n*2);
    int dst = 0;
    int left = 1;
    cf(right,1,n){
        fq[a[right]]++;
        if(fq[a[right]] == 1) dst++;
        while(dst > K){
            fq[a[left]]--;
            if(fq[a[left]] == 0) dst--;
            left++;
        }
        L[right] = left;
    }
    return L;
}

void solve() {
    ll n,k,l,r;
    cin >> n >> k >> l >> r;
    vector<ll> arr(n);
    f(i,0,n) cin >> arr[i];

    vector<int> comp = cmp(arr);
    comp.insert(comp.begin(),0); 

    vector<int> L1 = compute_L(comp, (int)k);
    vector<int> L2 = compute_L(comp, (int)k-1);

    ll ans = 0;
    cf(c,1,n){
        int low = max(L1[c], (int)(c - r + 1));
        int high = min((int)c, (int)(c - l + 1));
        int cntk = 0;
        if(low <= high) cntk = high - low + 1;

        int low2 = max(L2[c], (int)(c - r + 1));
        int high2 = min((int)c, (int)(c - l + 1));
        int cntk1 = 0;
        if(low2 <= high2) cntk1 = high2 - low2 + 1;

        ans += (cntk - cntk1);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
