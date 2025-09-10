#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int dfs(int n, int k)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (k > n)
        return 0;
    if (dp[n][k] != -1)
        return dp[n][k];
    return dp[n][k] = dfs(n - k, k) + dfs(n, k + 1);
}
int main()
{
    int n;
    cin >> n;
    dp.assign(n + 1, vector<int>(n + 1, -1));
    cout << dfs(n, 1);
}