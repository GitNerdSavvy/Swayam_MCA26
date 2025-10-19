// Problem: Common Divisors
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1081
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define ll long long
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define pb push_back
#define nline <<"\n";
#define out(async) cout<<async <<"\n";


void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }



void solve(){
	 int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    unordered_map<int, int> ump;
    for (int x : a) ump[x]++;

    for (int g = mx; g >= 1; g--) {
        int xnt = 0;
        for (auto &p : ump) {
            if (p.first % g == 0) xnt += p.second;
            if (xnt >= 2) break;
        }
        if (xnt >= 2) {
            cout << g;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
        solve();
	return 0;
}



