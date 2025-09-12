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

int n;
vll arr;
ll dp[5005][5005];
// ll func(int i, int j, bool flag) {
        // if (i > j)
            // return 0;
        // if(dp[i][j][flag] != -1) return dp[i][j][flag];
        // if (flag) {
            // return dp[i][j][flag]=max(arr[i] + func(i + 1, j, false),
                       // arr[j] + func(i, j - 1, false));
        // } else {
            // return dp[i][j][flag]=min(func(i + 1, j, true), func(i, j - 1, true));
        // }
    // }
void solve() {
    cin >> n;
    arr.resize(n);
    f(i,0,n) cin >> arr[i];

    f(i,0,n) dp[i][i] = arr[i];

    cf(len,2,n) {
        f(i,0,n-len+1) {
            int j = i + len - 1;
            dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
        }
    }

    ll total = accumulate(all(arr), 0LL);
    ll diff = dp[0][n-1];
    cout << (total + diff) / 2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
