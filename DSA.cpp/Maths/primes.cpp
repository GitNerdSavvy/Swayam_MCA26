#include <bits/stdc++.h>
using namespace std;

const int mx = 1e8;
const int mn = 1e8-50;

int main() {
    vector<int> arr(mx, 1);
    arr[0] = arr[1] = 0;

    for (int i = 2; i * i < mx; i++) {
        if (arr[i]) {
            for (int j = i * i; j < mx; j += i) {
                arr[j] = 0;
            }
        }
    }

    vector<int> primes;
    for (int i = mn; i < mx; i++) {
        if (arr[i]) primes.push_back(i);
    }

    for (auto it : primes) cout << it << " ";
}
