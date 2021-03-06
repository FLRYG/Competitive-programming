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
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(ll i=0;i<n;i++)
#define repn(i,n) for(ll i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<ll,ll> P;
// typedef pair<ll,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
ll const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,M;

int main(){
    cin>>N>>M;
    vector<vector<ll>> dp(N,vector<ll>(N,LINF));
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--, b--;
        dp[a][b]=c;
    }

    ll ans=0;
    rep(i,N) dp[i][i]=0;
    rep(k,N) rep(i,N) rep(j,N){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        // printf("%lld %lld %lld %lld\n",k+1,i+1,j+1,dp[i][j]);
        if(dp[i][j]<LINF) ans+=dp[i][j];
    } 

    cout<<ans<<endl;
    
    return 0;
}