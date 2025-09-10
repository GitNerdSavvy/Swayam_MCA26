#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f(i,s,e) for(ll i=s; i<e; i++)
#define cf(i,s,e) for(ll i=s; i<=e; i++)
#define rf(i,e,s) for(ll i=e-1; i>=s; i--)
#define pb push_back
#define eb emplace_back
#define nline << "\n";

template <class T>
void printv(vector<T> &v) { for (auto x : v) cout << x << " "; cout << "\n"; }

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll min(ll a, int b) { return a < b ? a : b; }
ll min(int a, ll b) { return a < b ? a : b; }
ll max(ll a, int b) { return a > b ? a : b; }
ll max(int a, ll b) { return a > b ? a : b; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a) { for (char &c : a) if (c >= 'a' && c <= 'z') c -= 32; return a; }
string to_lower(string a) { for (char &c : a) if (c >= 'A' && c <= 'Z') c += 32; return a; }
bool prime(ll a) { if (a <= 1) return false; for (ll i = 2; i * i <= a; ++i) if (a % i == 0) return false; return true; }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

bool safe_with(const deque<ll>& last, ll x) {
    if (last.size() < 4) return true;
    return !(last[0] < last[1] && last[1] < last[2] && last[2] < last[3] && last[3] < x) &&
           !(last[0] > last[1] && last[1] > last[2] && last[2] > last[3] && last[3] > x);
}

void solve() {
    ll n;
    cin >> n;
    vll arr(n);
    f(i, 0, n) cin >> arr[i];

    ll l = 0, r = n - 1;
    deque<ll> last;
    string ans;
    ans.reserve(n);

    f(step, 0, n) {
        bool okL = safe_with(last, arr[l]);
        bool okR = safe_with(last, arr[r]);
        char pick = '?';

        if (okL && !okR) pick = 'L';
        else if (okR && !okL) pick = 'R';
        else if (okL && okR) {
            deque<ll> Dl = last;
            if (Dl.size() == 4) Dl.pop_front();
            Dl.push_back(arr[l]);
            bool futureL = false;
            if (l + 1 <= r)
                futureL = safe_with(Dl, arr[l + 1]) || safe_with(Dl, arr[r]);
            else
                futureL = true;

            deque<ll> Dr = last;
            if (Dr.size() == 4) Dr.pop_front();
            Dr.push_back(arr[r]);
            bool futureR = false;
            if (l <= r - 1)
                futureR = safe_with(Dr, arr[l]) || safe_with(Dr, arr[r - 1]);
            else
                futureR = true;

            if (futureL && !futureR) pick = 'L';
            else if (futureR && !futureL) pick = 'R';
            else pick = 'L';
        } else pick = 'L';

        if (pick == 'L') {
            if (last.size() == 4) last.pop_front();
            last.push_back(arr[l]);
            ans.pb('L');
            l++;
        } else {
            if (last.size() == 4) last.pop_front();
            last.push_back(arr[r]);
            ans.pb('R');
            r--;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
