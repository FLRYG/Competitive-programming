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
typedef pair<ll,ll> P;

ll N;
vector<P> node[100001];
ll Q,K;
ll x[100000], y[100000];
ll dis[100001];

void dfs(ll m,ll p){
    repr(e,node[m]){
        if(e.first==p) continue;
        dis[e.first]+=dis[m]+e.second;
        dfs(e.first,m);
    }
}

int main(){
    cin>>N;
    rep(i,N-1){
        int a,b,c;
        cin>>a>>b>>c;
        node[a].push_back(P(b,c));
        node[b].push_back(P(a,c));
    }
    cin>>Q>>K;
    rep(i,Q) cin>>x[i]>>y[i];

    dfs(K,0);

    rep(i,Q){
        ll ans=dis[x[i]]+dis[y[i]];
        cout<<ans<<endl;
    }
}