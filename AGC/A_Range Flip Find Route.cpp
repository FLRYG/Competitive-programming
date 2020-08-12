#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int H,W;
char s[101][101];
int dp[101][101];

int main(){
    cin>>H>>W;
    repn(i,H) repn(j,W) cin>>s[i][j];
    repn(i,H) fill(dp[i]+1,dp[i]+W+1,INF);

    dp[1][1]=0;
    repn(i,H){
        repn(j,W){
            if(i<H){
                int cnt=dp[i][j];
                if(s[i][j]!=s[i+1][j]) cnt++;
                dp[i+1][j]=min(dp[i+1][j],cnt);
            }
            if(j<W){
                int cnt=dp[i][j];
                if(s[i][j]!=s[i][j+1]) cnt++;
                dp[i][j+1]=min(dp[i][j+1],cnt);
            }
        }
    }
    int ans=dp[H][W]/2;
    if(s[1][1]=='#' || s[H][W]=='#') ans++;

    cout<<ans<<endl;
}



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