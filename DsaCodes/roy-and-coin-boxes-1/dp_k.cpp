// Problem: K - Stones
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_k
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

int n;
vi arr;
 
 int func(int l,int h,int k){
 	if(k==0) return 0;
 	if(l==h) return 0;
 	
 	int ans=0;
 	if(arr[h]<=k){
 		ans+=1+func(l,h-1,k-arr[h]);
 	}else{
 		ans+=1+func(l+1,h,k-arr[l]);
 	}
 	return ans;
 }
 void solve() {
 	int k;
    cin>>n>>k;
    
    arr.resize(n);
    sort(all(arr));
    f(i,0,n) cin>>arr[i];
    if(func(0,n-1,k)%2){
    	cout<<"First" nline
    }else{
    	cout<<"Second" nline
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