#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0) {
            cout<<"Not prime";
            return 0;
        }
    }
    cout<<"Prime";
    return 0;
}