// Problem: B - Fibonacci Reversed
// Contest: AtCoder - AtCoder Beginner Contest 421
// URL: https://atcoder.jp/contests/abc421/tasks/abc421_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

ll fil(ll ans){
	string res=to_string(ans);
    reverse(res.begin(),res.end());
    return stoll(res);
}

ll func(int a,int b){
	ll t=0;
	 for (int i = 0; i < 8; i++) {
         t = a + b;
        a = b;
        b = fil(t);
    }
    return fil(t);
}

 
 
 void solve() {
    int a,b;
    cin>>a>>b;
    ll ans=func(a,b);
    // string res=to_string(ans);
    // reverse(res.begin(),res.end());
    cout<<ans<<"\n";

}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // int t;
   // cin>>t;
	//while(t--){
        solve();
	//}
	return 0;
}