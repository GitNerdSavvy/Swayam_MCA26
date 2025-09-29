#include<bits/stdc++.h>
using namespace std;
struct matrix
{
    int mat[2][2];
};
matrix mul(matrix A,matrix B){
    matrix c;
    for(int row=0;row<2;row++){
        for(int col=0;col<2;col++){
            int t=0;

            for(int i=0;i<2;i++){
                t+=A.mat[row][i] *B.mat[i][col];
            }
            c.mat[row][col]=t;
        }
    }
    return c;
}

matrix identity(){
    matrix A;
    A.mat[0][0]=1;A.mat[0][1]=0;
    A.mat[1][0]=0;A.mat[1][1]=1;
    return A;
}

matrix power(matrix A,int n){
    if(n==0) return identity();
    matrix X=power(A,n/2);
    if(n%2==0){
        return mul(X,X);
    }else{
        return mul(mul(X,X),A);
    }
}

int nth_fib(int n){
    matrix fib;
    fib.mat[0][0]=1,fib.mat[0][1]=1;
    fib.mat[1][0]=1,fib.mat[1][1]=0;
    return power(fib,n).mat[0][0];
}

int main(){
    int n;
    cin>>n;
    cout<<nth_fib(n);


    // int n;
    // cin>>n;
    // for(int i=1;i<=n;i++){
    //     cout<<nth_fib(i)<<" ";
    // }
}