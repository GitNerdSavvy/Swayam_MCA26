// Problem: Book Shop
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1158
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

int n;
vector<int>books,pages;
 // int dp[1005][100005];
 // int func(int i,int m){
 	// if(i>=n) return 0;
 	// if(m<=0) return 0;
 	// if(dp[i][m] != -1) return dp[i][m];
 	// int ans=0;
 	// ans=func(i+1,m);
 	// if(books[i]<=m){
 		// ans=max(ans,pages[i]+func(i+1,m-books[i]));
 	// }else{
 		// ans=max(ans,func(i+1,m));
 	// }
 	// return dp[i][m]= ans;
 // }
//  
//  
 void solve() {
 	int m;
    cin>>n>>m;
    books.resize(n);
    pages.resize(n);
    f(i,0,n) cin>>books[i];
    f(i,0,n) cin>>pages[i];
     vector<int> dp(m + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = m; j >= books[i]; j--) {
            dp[j] = max(dp[j], dp[j - books[i]] + pages[i]);
        }
    }

    cout << dp[m] << "\n";

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