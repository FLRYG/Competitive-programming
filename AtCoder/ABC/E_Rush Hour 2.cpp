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
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

struct Edge{
    ll to,cost,D;
    Edge(): to(0), cost(0), D(D) {}
    Edge(ll _to, const ll _cost, ll _D): to(_to), cost(_cost), D(_D){}
    bool operator<(const Edge &e) const{ return cost < e.cost; }
    bool operator>(const Edge &e) const{ return cost > e.cost; }
    bool operator<=(const Edge &e) const{ return !(cost > e.cost); }
    bool operator>=(const Edge &e) const{ return !(cost < e.cost); }
};

void dijkstra(vector<vector<Edge>> &G, vector<ll> &cost, ll s){
    cost.assign(G.size(),LINF);
    priority_queue<Edge,vector<Edge>,greater<Edge>> que;
    que.push(Edge(s,0,0));
    while(!que.empty()){
        Edge e=que.top(); que.pop();
        if(e.cost>=cost[e.to]) continue;
        cost[e.to]=e.cost;
        for(auto next:G[e.to]){
            // ll time=next.D/(e.cost+1);
            // ll wait=1;
            // while(time>next.D/(e.cost+1+wait)+wait){
            //     time=next.D/(e.cost+1+wait)+wait;
            //     wait++;
            // }
            ll low=e.cost, high=LINF;
            while(high-low>=3){
                ll l=low+(high-low)/3;
                ll r=high-(high-low)/3;
                // cout<<low<<' '<<l<<' '<<r<<' '<<high<<endl;
                ll lval=next.D/(1+l)+l-e.cost;
                ll rval=next.D/(1+r)+r-e.cost;
                if(lval>rval) low=l;
                else high=r;
            }
            ll time=LINF;
            rep(i,high-low+1) time=min(time,next.D/(1+low+i)+low+i-e.cost);
            que.push(Edge(next.to,e.cost+next.cost+time,0));
        }
    }
}

ll N,M;

int main(){
    cin>>N>>M;
    vector<vector<Edge>> G(N);
    rep(i,M){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        a--, b--;
        G[a].push_back(Edge(b,c,d));
        G[b].push_back(Edge(a,c,d));
    }

    vector<ll> cost(N,0);
    dijkstra(G,cost,0);
    // rep(i,N) cout<<i<<' '<<cost[i]<<endl;
    
    ll ans=cost[N-1];
    if(ans==LINF) ans=-1;

    cout<<ans<<endl;
    
    return 0;
}