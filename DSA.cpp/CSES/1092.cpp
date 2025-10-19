// Problem: Two Sets
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1092
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
	int n;
	cin>>n;
	ll sum=n*(n+1)/2;
	if(sum&1){
		no();
		return;
	}
	 yes();
	 ll target = sum / 2;
    vll a, b;

    for (ll i = n; i >= 1; i--) {
        if (i <= target) {
            a.push_back(i);
            target -= i;
        } else {
            b.push_back(i);
        }
    }

    cout << a.size() << "\n";
    for (auto x : a) cout << x << " ";
    cout << "\n" << b.size() << "\n";
    for (auto x : b) cout << x << " ";
    cout << "\n";
	
	
	
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();
	
	return 0;
}



