// Problem: Dice Combinations
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1633
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

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

#define f(i, s, e) for (long long int i = s; i < e; i++)
#define cf(i, s, e) for (long long int i = s; i <= e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define pb push_back
#define eb emplace_back
#define nline << "\n";

int dp[1000005];

int func(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 3;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = func(n - 1) + func(n - 2);
}

void solve()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << func(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin>>t;
    // while(t--){
    solve();
    //}
    return 0;
}