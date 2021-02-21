#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int X[17];
int Y[17];
int Z[17];

int main(){
    cin>>N;
    vector<vector<int>> G(N,vector<int>(N));
    rep(i,N) cin>>X[i]>>Y[i]>>Z[i];
    rep(i,N) rep(j,N){
        G[i][j]=abs(X[j]-X[i])+abs(Y[j]-Y[i])+max(0,Z[j]-Z[i]);
    }

    vector<vector<int>> dp(1<<N,vector<int>(N,INF));
    dp[(1<<N)-1][0]=0;
    for(int S=(1<<N)-2;S>=0;S--){
        rep(v,N){
            rep(u,N){
                dp[S][v]=min(dp[S][v],dp[S|1<<u][u]+G[v][u]);
            }
        }
    }

    cout<<dp[0][0]<<endl;
    
    return 0;
}