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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N;

void dfs(int v, int p, ll d, vector<ll> &dist, vector<vector<P>> &G){
    dist[v]=d;
    repr(e,G[v]){
        if(e.first!=p) dfs(e.first,v,d^e.second,dist,G);
    }
}

int main(){
    cin>>N;
    vector<vector<P>> G(N,vector<P>());
    rep(i,N-1){
        ll u,v,w;
        cin>>u>>v>>w;
        u--, v--;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    vector<ll> dist(N,0);
    dfs(0,-1,0,dist,G);

    vector<ll> cnt(60,0);
    rep(i,N){
        rep(j,60) cnt[j]+=dist[i]>>j&1;
    }

    ll ans=0;
    ll two=1;
    rep(i,60){
        ans+=cnt[i]*(N-cnt[i])%MOD*two%MOD;
        ans%=MOD;
        two*=2;
        two%=MOD;
    }

    cout<<ans<<endl;
    
    return 0;
}