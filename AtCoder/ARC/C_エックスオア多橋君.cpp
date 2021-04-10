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
typedef pair<int,int> P;
typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,X;

void f(ll pos, ll prev, vector<ll> &val, vector<vector<P>> &G){
    repr(e,G[pos]){
        if(e.first==prev) continue;
        val[e.first]=val[pos]^e.second;
        f(e.first,pos,val,G);
    }
}

int main(){
    cin>>N>>X;
    vector<vector<P>> G(N,vector<P>(0));
    rep(i,N-1){
        ll x,y,c;
        cin>>x>>y>>c;
        G[x-1].push_back({y-1,c});
        G[y-1].push_back({x-1,c});
    }

    vector<ll> val(N,0);
    f(0,-1,val,G);

    map<ll,ll> m;
    rep(i,N) m[val[i]]++;

    ll ans=0;
    rep(i,N){
        ll v=X^val[i];
        if(val[i]==v) ans+=m[v]-1;
        else ans+=m[X^val[i]];
    }
    ans/=2;

    cout<<ans<<endl;

    return 0;
}