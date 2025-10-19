// Problem: Missing Number
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1083
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;


// -------------Macros Start--------------


#define all(x) x.begin(),x.end()
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define f(i,s,e) for(int i=s;i<e;i++)
#define fll(i,s,e) for(long long int i=s;i<e;i++)
#define pb push_back
#define nline <<"\n";
#define out(async) cout<<async <<"\n";

void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// -------------Macros End----------------

// ---Tutorial---
// 1.Read the problem carefully
// 2.Think first about Brute Force Approach
// 3.Think Greedy
// 4.Think about Optimisation
// 5.Think about Edge Cases



// -------------------Global Variables---------------





void solve(){
	ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    ll s = 0;
    for (int i = 0; i < n - 1; i++) {
        ll x;
        cin >> x;
        s += x;
    }
    cout << sum - s << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
	return 0;
}



