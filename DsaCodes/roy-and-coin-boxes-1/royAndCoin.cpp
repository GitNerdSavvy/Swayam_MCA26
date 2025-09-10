#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
vector<ll> L(1000005, 0), R(1000005, 0);

void solve() {
    cin >> n >> m;

    vector<ll> f(n + 2, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        L[l]++;
        R[r]++;
    }

    f[1] = L[1];
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + L[i] - R[i - 1];
    }

    vector<ll> c(1000005, 0);
    for (int i = 1; i <= n; i++) {
        c[f[i]]++;
    }

    for (int i = 1000003; i >= 1; i--) {
        c[i] += c[i + 1];
    }

    int q;
    cin >> q;
    while (q--) {
        int num;
        cin >> num;
        cout << c[num] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
