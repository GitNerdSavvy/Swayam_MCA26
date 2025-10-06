// Problem: Sliding Window ump Values
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3222
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



void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<ll, int> ump;
    vector<int> ans;
    int cnt = 0;

    int l = 0, h = 0;

    while (h < n) {
        if (ump[arr[h]] == 0) cnt++;
        ump[arr[h]]++;
        h++;

        if (h - l > k) {
            ump[arr[l]]--;
            if (ump[arr[l]] == 0) cnt--;
            l++;
        }

        if (h - l == k) ans.push_back(cnt);
    }

    for (int x : ans) cout << x << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin>>t;
	// while(t--){
        solve();
	// }
	return 0;
}