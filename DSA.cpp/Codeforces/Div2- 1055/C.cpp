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

void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
 
void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    f(i,0,n) cin >> a[i];

    vi pos0, pos1;
    f(i,0,n) {
        if(a[i]==0) pos0.pb(i);
        else pos1.pb(i);
    }

    auto build_pref = [](vi &pos) -> vll {
        int m = pos.size();
        int blocks = m / 3;
        vll pref(blocks + 1, 0);
        f(i,0,blocks) {
            int x1 = pos[3*i], x2 = pos[3*i+1], x3 = pos[3*i+2];
            ll cost = min(x3 - x2, x2 - x1);
            pref[i+1] = pref[i] + cost;
        }
        return pref;
    };

    vll pref0 = build_pref(pos0);
    vll pref1 = build_pref(pos1);

    auto solve_query = [&](int l, int r) -> ll {
        auto zl_it = lower_bound(all(pos0), l);
        auto zr_it = upper_bound(all(pos0), r);
        int zl = zl_it - pos0.begin();
        int zr = zr_it - pos0.begin() - 1;
        int cnt0 = zr - zl + 1;
        if(cnt0 < 0) cnt0 = 0;

        auto ol_it = lower_bound(all(pos1), l);
        auto orr_it = upper_bound(all(pos1), r);
        int ol = ol_it - pos1.begin();
        int orr = orr_it - pos1.begin() - 1;
        int cnt1 = orr - ol + 1;
        if(cnt1 < 0) cnt1 = 0;

        if(cnt0 % 3 != 0 || cnt1 % 3 != 0) return -1;

        ll total = 0;
        if(cnt0 > 0) {
            if(zl % 3 != 0) return -1;
            int bL = zl / 3, bR = zr / 3;
            total += pref0[bR+1] - pref0[bL];
        }
        if(cnt1 > 0) {
            if(ol % 3 != 0) return -1;
            int bL = ol / 3, bR = orr / 3;
            total += pref1[bR+1] - pref1[bL];
        }
        return total;
    };

    f(i,0,q) {
        int l,r;
        cin >> l >> r;
        l--; r--; // convert to 0-based
        cout << solve_query(l,r) << "\n";
    }
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
