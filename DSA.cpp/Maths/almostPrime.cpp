// #include<bits/stdc++.h>
// using namespace std;

// bool isPrime(int x){
//     for(int i=2;i*i<=x;i++){
//         if(x%i==0) return false;
//     }
//     return true;
//     // tc - O(sqrt(x))
// }

// bool almost_prime(int n){

//     for(int i=2;i*i<=n;i++){
//         if(n%i==0){
//             if(isPrime(i) && isPrime(n/i) && i!=n){
//                 return true;
//             }
//         }
//     }
//     return false;
//     // tc - O(sqrt(n))
// }
// int main(){
//     int n;
//     cin>>n;
//     if(almost_prime(n)){
//         cout<<"Yes\n";
//     }else{
//         cout<<"No\n";
//     }
//     // tc for 1 testcase O(sqrt(n))
//     // for 1e5 testcase ,not work
// }


// lets optimize

#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
bool prime[mx];
int spf[mx];
void prime_sieve(){
    for(int i=1;i<=mx;i++){
        prime[i]=true; spf[i] = 0;
    }
    prime[1]=false;prime[0]=false;
    // int lim=__sqrt(mx);
    for(int i=2;i*i<=mx;i++){
        if(prime[i]){
            for(int j=i*i;j<=mx;j+=i){
                prime[j]=false;
            }
        }
    }
    spf[1]=1;
    for(int i=2;i<=mx;i++){
        if(prime[i]){
            for(int j=i;j<mx;j+=i){
                if(spf[j]==0){
                    spf[j]=i;
                }else{
                    continue;
                }
            }
        }
    }
     for(int i=2;i<mx;i++){
        if(prime[i]) spf[i]=i;
    }
}

// bool almostprime[mx];
int func(int n){
    // for(int i=1;i<=n;i++){
    //     if(prime[i]){
    //         for(int j=i;j<=n;j+=i){
    //             if(prime[j/i] && j/i!=i){
    //                 almostprime[j]=true;
    //             }
    //         }
    //     }
    // }
    // int ans=0;
    // for(int i=1;i<=n;i++){
    //     if(almostprime[i]){
    //         ans++;
    //     }
    // }
    // return ans;

    int ans=0;
    for(int i=1;i<=n;i++){
        int a=spf[i];
        int b=spf[n/a];
        if(a!=b && prime[a] && prime[b]){
            ans++;
        }
    }
    return ans;
    
}

int main(){
    prime_sieve();
    int t;  // t can be 1e5
    cin>>t;
    while(t--){
        int n;  // n can be 1e6
        cin>>n;
        cout<<func(n)<<"\n";
    }
}