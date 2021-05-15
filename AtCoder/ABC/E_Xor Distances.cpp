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

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

int N;

void f(int v, int p, int k, vector<ll> &d, vector<vector<P>> &G){
    d[v]=k;
    repr(e,G[v]) if(e.first!=p){
        f(e.first,v,k+1,d,G);
    }
}

ll g(int v, int p, vector<ll> &cnt, vector<vector<P>> &G){
    ll res=1;
    repr(e,G[v]) if(e.first!=p){
        res+=g(e.first,v,cnt,G);
    }
    return cnt[v]=res;
}

int main(){
    cin>>N;
    vector<vector<P>> G(N,vector<P>());
    rep(i,N-1){
        int u,v,w;
        cin>>u>>v>>w;
        u--, v--;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    vector<ll> d(N), cnt(N);
    f(0,-1,0,d,G);
    g(0,-1,cnt,G);

    ll ans=0;
    rep(i,N) repr(j,G[i]){
        if(d[i]>d[j.first]) ans+=(cnt[i]*(N-cnt[i]))&1?j.second:0;
        else ans+=(cnt[j.first]*(N-cnt[j.first]))&1?j.second:0;
        ans%=MOD;
    }
    ans*=mpow(2,MOD-2);

    cout<<ans<<endl;
    
    return 0;
}