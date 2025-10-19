// Problem: Permutations
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1070
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
 
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define nline <<"\n";
#define out(asy) cout<<asy nline
#define MOD 1000000007

 
 
 void solve() {
    int n;
    cin>>n;
    if(n==1){
    	out(1)
    	return;
    }
    if(n<=3){
    	out("NO SOLUTION")
    	return;
    }
    if(n==4){
    	out("2 4 1 3")
    	return;
    }
	for(int i=n;i>0;i--){
		if(i%2==0){
			cout<<i<<" ";
		}
	}
	for(int i=n;i>0;i--){
		if(i&1){
			cout<<i<<" ";
		}
	}
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}