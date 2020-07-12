#include <iostream>
#include <queue>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;

/*
const int INF=100100;
typedef pair<int,int> P;

int H,W;
char grid[105][105];
int ans[105][105];
queue<P> que;
bool mark[105][105];
char vect[105][105];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>grid[i][j];
    rep(i,100) rep(j,100) ans[i][j]=INF;

    if(grid[1][1]=='.'){
        ans[1][1]=0;
    }else{
        ans[1][1]=1;
    }
    que.push(P(1,1));
    mark[1][1]=true;
    while(que.size()>0){
        P p=que.front();
        que.pop();

        int i=p.first;
        int j=p.second;

        if(i<H){
            if(grid[i+1][j]=='.'){
                ans[i+1][j]=min(ans[i+1][j],ans[i][j]);
            }else{
                ans[i+1][j]=min(ans[i+1][j],ans[i][j]+1);
            }
            if(!mark[i+1][j]){
                que.push(P(i+1,j));
                mark[i+1][j]=true;
            }
        }

        if(j<W){
            if(grid[i][j+1]=='.'){
                ans[i][j+1]=min(ans[i][j+1],ans[i][j]);
            }else{
                ans[i][j+1]=min(ans[i][j+1],ans[i][j]+1);
            }
            if(!mark[i][j+1]){
                que.push(P(i,j+1));
                mark[i][j+1]=true;
            }  
        }
    }

    cout<<ans[H][W]<<endl;
}
*/