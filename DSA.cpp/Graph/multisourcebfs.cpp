#include<bits/stdc++.h>
using namespace std;

#define vii vector<vector<int>>
#define f(i,s,e) for(int i=0;i<e;i++)


int bfs(vii &mat,int n,int m){
        vii vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;

        f(i,0,n)
            f(j,0,m)
                if(mat[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
        
        int time=0;
        vii dir={{1,0},{0,1},{-1,0},{0,-1}};

        while(!q.empty()){
           auto elem = q.front(); q.pop();
            int row = elem.first.first;
            int col = elem.first.second;
             time = elem.second;

             f(d,0,4){
                int r=row+dir[d][0];
                int c=col+dir[d][1];

                if(r>=0 && c>=0 && r<n && c<m && vis[r][c]!=2 && mat[r][c]==1){
                        q.push({{r,c},time+1});
                        vis[r][c]=2;
                }
             }
        }

        f(i,0,n){
            f(j,0,m){
                if(vis[i][j]!=2 && mat[i][j]==1){
                    return -1;
                }
            }
        }

        return time;
}


int main(){
        cout<<"Enter grid details\n";
        int n,m;
        cin>>n>>m;
        vii mat(n,vector<int>(m));
        f(i,0,n){
            f(j,0,m){
                cin>>mat[i][j];
            }
        }
        cout<<"Total time taken: "<<bfs(mat,n,m);
}