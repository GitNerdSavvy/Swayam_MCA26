#include<bits/stdc++.h>
using namespace std;
// int func(int n){
//     int ans=0;
//     for(int i=1;i*i<=n;i++){
//         if(n%i==0){
//             int j=n/i;
//             if(i<j && (i%2==j%2)){
//                 cout<<(i+j)/2<<" "<<(j-i)/2<<"\n";
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }

const int mx=1e6+5;
int arr[mx];
void compute(){
    for(int i=1;i<=mx;i++){
        for(int j=i;j<=mx;j+=i){
            arr[j]++;
        }
    }
}


int main(){
    compute();
    int n;
    cin>>n;
    cout<<arr[n]/2<<"\n";
}