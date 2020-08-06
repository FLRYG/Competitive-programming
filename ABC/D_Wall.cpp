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
ll const MOD=1000000007;
ll const INF=1001001001;
typedef pair<int,int> P;

int H,W;
int c[10][10];
int A[200][200];
int cost[10][10];

int main(){
    cin>>H>>W;
    rep(i,10) rep(j,10) cin>>c[i][j];
    rep(i,H) rep(j,W) cin>>A[i][j];
    rep(i,10) fill(cost[i],cost[i]+10,INF);

    rep(s,10){
        cost[s][s]=0;
        priority_queue<P,vector<P>,greater<P>> que;
        que.push(P(s,0));
        while(!que.empty()){
            P p=que.top();
            que.pop();
            if(cost[s][p.first]<p.second) continue;
            rep(i,10){
                if(cost[s][p.first]+c[p.first][i]<cost[s][i]){
                    cost[s][i]=cost[s][p.first]+c[p.first][i];
                    que.push(P(i,cost[s][i]));
                }
            }
        }
    }

    int ans=0;
    rep(i,H){
        rep(j,W){
            if(A[i][j]==-1) continue;
            ans+=cost[A[i][j]][1];
        }
    }

    cout<<ans<<endl;
}