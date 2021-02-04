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

int N,M;
vector<vector<int>> G;
vector<int> dp;

int dfs(int node){
    if(dp[node]!=-1) return dp[node];
    if(G[node].size()==0){
        dp[node]=0;
        return 0;
    }
    int res=0;
    repr(e,G[node]){
        res=max(res,dfs(e));
    }
    dp[node]=res+1;
    return res+1;
}

int main(){
    cin>>N>>M;
    G=vector<vector<int>>(N,vector<int>(0));
    int x,y;
    rep(i,M){
        cin>>x>>y;
        G[x-1].push_back(y-1);
    }

    dp=vector<int>(N,-1);
    int ans=0;
    rep(i,N){
        ans=max(ans,dfs(i));
        // cout<<i+1<<' '<<dfs(i)<<endl;
    }

    cout<<ans<<endl;
    
    return 0;
}