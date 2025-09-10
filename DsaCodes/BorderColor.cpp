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
typedef unsigned long long int uint64;

vector<pair<ll,ll>> res;

void dfs(vector<vector<ll>>& grid, ll r, ll c, ll color,ll cl) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != cl) return;
    grid[r][c] = -color;
    dfs(grid, r + 1, c, color, cl);
    dfs(grid, r - 1, c, color, cl);
    dfs(grid, r, c + 1, color, cl);
    dfs(grid, r, c - 1, color, cl);

    if (!(r == 0 || c == 0 || r == grid.size() - 1 || c == grid[0].size() - 1 
        || grid[r + 1][c] != -color || grid[r - 1][c] != -color 
        || grid[r][c + 1] != -color || grid[r][c - 1] != -color)) {
        res.push_back({r, c});
    }
}

vector<vector<ll>> colorBorder(vector<vector<ll>>& grid, ll row, ll col, ll color) {
    ll cl=grid[row][col];
    if(cl==color) return grid;
    res.clear();
    dfs(grid,row,col,color,cl);
    for (auto it : res) {
        ll i = it.first;
        ll j = it.second;
        grid[i][j] = cl;
    }
    f(i,0,grid.size()){
        f(j,0,grid[0].size()){
            if(grid[i][j]<0){
                grid[i][j]*=-1;
            }
        }
    }
    return grid;
}

void solve() {
    string s;
    cin.ignore();
    getline(cin, s);
    vector<vector<ll>> grid;
    vector<ll> row;
    string num = "";
    for (char c : s) {
        if (isdigit(c)) num += c;
        else {
            if (!num.empty()) {
                row.push_back(stoll(num));
                num = "";
            }
            if (c == ']') {
                if (!row.empty()) {
                    grid.push_back(row);
                    row.clear();
                }
            }
        }
    }
    ll r, c, color;
    cin >> r >> c >> color;
    vector<vector<ll>> ans = colorBorder(grid,r,c,color);
    f(i,0,ans.size()){
        f(j,0,ans[0].size()){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
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
