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
vector<int> dp;

int func(int k){
    if(k==0) return 0;
    if(dp[k]!=-1) return dp[k];
    f(i,0,n){
        if(k-arr[i]>=0 && func(k-arr[i])==0){
            return dp[k]=1;
        }
    }
    return dp[k]=0;
}
 
void solve() {
    int k;
    cin>>n>>k;
    arr.resize(n);
    f(i,0,n) cin>>arr[i];
    dp.assign(k+1,-1);
    if(func(k)) cout<<"First" nline
    else cout<<"Second" nline
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
