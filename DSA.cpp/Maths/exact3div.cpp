#include <bits/stdc++.h>
using namespace std;

// int sqrt(int n)
// {
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (i * i == n)
//         {
//             return i;
//         }
//     }
//     return 0;
// }
// bool isPrime(int n)
// {
//     if (n == 0 || n == 1)
//         return false;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }
// bool func(int n)
// {
//     if (isPrime(sqrt(n)))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

const int mx = 1e5 + 5;
bool isPrime[mx];
set<long long>s;

void sieve(){
    memset(isPrime,true,sizeof isPrime);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=mx;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=mx;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i=1;i<=mx;i++){
        if(isPrime[i]){
            s.insert(i*i);
        }
    }
}
bool check(long long n){
    if(s.find(n) != s.end()){
        return true;
    }else{
        return false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   sieve();
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << check(n) << "\n";
    }
}