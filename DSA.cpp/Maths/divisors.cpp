#include<bits/stdc++.h>
using namespace std;
// int div(int n){
//     int ans=0;
//     for(int i=1;i*i<=n;i++){
//         if(n%i==0) {
//             ans++;
//              if(i!= n/i) ans++;
//         }
       
//     }
//     return ans;
// }

#define mx 100007
int arr[mx];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=mx;i++){
        for(int j=i;j<=mx;j+=i){
            arr[j]++;
        }
    }
    cout<<arr[n];
}