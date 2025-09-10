// Problem: A - 2x2 Erasing
// Contest: AtCoder - AtCoder Regular Contest 205 (Div. 2)
// URL: https://atcoder.jp/contests/arc205/tasks/arc205_a
// Memory Limit: 1024 MB
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




const int MX = 505;
int B[MX][MX];
int P[MX][MX];
int N, Q;
 
 
 void solve() {
     cin >> N >> Q;
    vector<string> grid(N+1);
    for (int i = 1; i <= N; i++) cin >> grid[i];

    f(i,1,N) {
        f(j,1,N) {
            if (grid[i][j-1] == '.' && grid[i][j] == '.' &&
                grid[i+1][j-1] == '.' && grid[i+1][j] == '.') {
                B[i][j] = 1;
            }
        }
    }

   f(i,1,N) {
        f(j,1,N) {
            P[i][j] = B[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1];
        }
    }

    while (Q--) {
        int U, D, L, R;
        cin >> U >> D >> L >> R;

        int ans = 0;
        if (D - 1 >= U && R - 1 >= L) {
            ans = P[D-1][R-1] - P[U-1][R-1] - P[D-1][L-1] + P[U-1][L-1];
        }
        cout << ans << "\n";
    }

}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // int t;
   // cin>>t;
	//while(t--){
        solve();
	//}
	return 0;
}