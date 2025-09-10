// Problem: F - LCS
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_f
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

string s1, s2;
int n, m;
int dp[3005][3005];  

int func(int i, int j) {
    if (i == n || j == m) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j]) dp[i][j] = 1 + func(i+1, j+1);
    else dp[i][j] = max(func(i+1, j), func(i, j+1));

    return dp[i][j];
}

void solve() {
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    memset(dp, -1, sizeof dp);

    func(0, 0);

   
    string lcs = "";
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j]) {
            lcs += s1[i];
            i++; j++;
        } else if (dp[i+1][j] >= dp[i][j+1]) i++;
        else j++;
    }

    cout << lcs << "\n";
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