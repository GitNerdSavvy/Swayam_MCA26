#include<iostream>
#include<vector>
using namespace std;
vector<int>dp;

int fib(int n){
    if(n==0 || n==1) return n;
  
   return fib(n-1)+fib(n-2);

   
}
int topDown(int n){
	 if(n==0 || n==1) return n;
   if(dp[n]!=-1) return dp[n];
   return dp[n]=fib(n-1)+fib(n-2);
}
int bottomUp(int n){
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int main(){
    int n,t;
    //cout<<"Enter Num";
    cin >> n;
    dp.clear();
    dp.resize(n+1,-1);
    while(n--){
    	cin>>t;
    	//cout<<fib(t)<<endl;
    	//cout<<topDown(t)<<endl;
    	cout<<bottomUp(t)<<endl;
    	
    }
    

    return 0;
}