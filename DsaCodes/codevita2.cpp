#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int minStringFactor(const string& X, const string& Y, int S, int R) {
    int n = X.length();
    int m = Y.length();
    
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    
    string revY = Y;
    reverse(revY.begin(), revY.end());

    for (int i = 0; i < n; ++i) {
        for (int len = 1; len <= m && i + len <= n; ++len) {
            if (X.substr(i, len) == Y.substr(0, len)) {
                dp[i + len] = min(dp[i + len], dp[i] + S);
            }
            if (X.substr(i, len) == revY.substr(0, len)) {
                dp[i + len] = min(dp[i + len], dp[i] + R);
            }
        }
    }

    return (dp[n] == INF) ? -1 : dp[n];
}

int main() {
    string X, Y;
    cin >> X >> Y;
    int S, R;
    cin >> S >> R;

    int result = minStringFactor(X, Y, S, R);

    if (result == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
