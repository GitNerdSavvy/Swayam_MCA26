#include<bits/stdc++.h>
using namespace std;
class matrix{
    public:
    int mat[3][3];
};
matrix mul(matrix A,matrix B){
    matrix c;
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            int t=0;

            for(int i=0;i<3;i++){
                t+=A.mat[row][i] *B.mat[i][col];
            }
            c.mat[row][col]=t;
        }
    }
    return c;
}

matrix identity(){
    matrix A;
    A.mat[0][0]=1;A.mat[0][1]=0;A.mat[0][2]=0;
    A.mat[1][0]=0;A.mat[1][1]=1;A.mat[1][2]=0;
    A.mat[2][0]=0;A.mat[2][1]=0;A.mat[2][2]=1;
    return A;
}

matrix power(matrix trib,int n){
    if(n==0) return identity();
    matrix x= power(trib,n/2);
    if(n&1){
        return mul(mul(x,x),trib);
    }else{
        return mul(x,x);
    }

}
int get_nth_tri(int n){
    matrix trib;
    trib.mat[0][0]=1,trib.mat[0][1]=1,trib.mat[0][2]=1;
    trib.mat[1][0]=1,trib.mat[1][1]=0,trib.mat[1][2]=0;
    trib.mat[2][0]=0,trib.mat[2][1]=1,trib.mat[2][2]=0;
    return power(trib,n).mat[0][0];
}
int main(){
    int n;
    cin>>n;
    // cout<<n<<"th tribonacci number is:"<<get_nth_tri(n-1);
    for(int i=1;i<=n;i++){
        cout<<get_nth_tri(i)<<" ";
    }
}