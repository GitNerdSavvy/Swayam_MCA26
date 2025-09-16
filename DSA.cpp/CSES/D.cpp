// Problem: D. Destruction of the Dandelion Fields
// Contest: Codeforces - Codeforces Round 1050 (Div. 4)
// URL: https://codeforces.com/contest/2148/problem/D
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
 
void solve() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    vector<long long> odds;
    long long sum = 0;

    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        } else {
            odds.push_back(arr[i]);
        }
    }

    long long ans = 0;
    int cnt = odds.size();

    if (cnt == 0) {
        ans = 0;
    } else {
        sort(odds.begin(), odds.end());
        long long csum = 0;
        int nsum = cnt / 2; 
        for (int i = 0; i < nsum; i++) {
            csum += odds[i];
        }
        long long td = accumulate(odds.begin(), odds.end(), 0LL);
        long long oc = td - csum;
        ans = sum + oc;
    }

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