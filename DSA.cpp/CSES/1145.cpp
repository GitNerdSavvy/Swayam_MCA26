#include <bits/stdc++.h>
using namespace std;

#define vll vector<long long>

int n;
vll arr;
int dp[100005];

int func(int i) {
    if(i == n) return 0; 
    if(dp[i] != -1) return dp[i];

    int ans = 1; 
    for(int j = i + 1; j < n; j++) {
        if(arr[j] > arr[i]) {
            ans = max(ans, 1 + func(j));
        }
    }

    return dp[i] = ans;
}

void solve() {
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    memset(dp, -1, sizeof(dp));

    int lis = 0;
    for(int i = 0; i < n; i++) {
        lis = max(lis, func(i));
    }

    cout << lis << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
