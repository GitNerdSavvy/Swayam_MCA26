// Problem: Coin Piles
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1754
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
	ll a,b;
	cin>>a>>b;
	if((a+b)%3==0 && max(a, b) <= 2 * min(a, b)){
		yes();
	}else{
		no();
	}
	
	
	
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
	while(t--){
        solve();
	}
	return 0;
}



