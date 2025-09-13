// Problem: A - Stage Clear
// Contest: AtCoder - AtCoder Beginner Contest 422
// URL: https://atcoder.jp/contests/abc422/tasks/abc422_a
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
#define MOD 1000000007

 
 
 void solve() {
    string s;
    cin >> s;

    int pos = s.find('-');
    int a = stoi(s.substr(0, pos));
    int b = stoi(s.substr(pos + 1));
    if(b<8){
    	cout<<a<<"-"<<b+1;
    }else{
    	cout<<a+1<<"-"<<1;
    }

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