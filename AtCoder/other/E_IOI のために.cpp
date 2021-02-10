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
// typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

struct Edge{
    ll to,cost;
    Edge(): to(0), cost(0) {}
    Edge(const ll &_to, const ll &_cost)
    : to(_to), cost(_cost)
    {}
    bool operator<(const Edge &e) const{ return cost < e.cost; }
    bool operator>(const Edge &e) const{ return cost > e.cost; }
    bool operator<=(const Edge &e) const{ return !(cost > e.cost); }
    bool operator>=(const Edge &e) const{ return !(cost < e.cost); }
};

void dijkstra(vector<vector<Edge>> &G, vector<ll> &cost, ll s){
    for(ll i=0;i<cost.size();i++) cost[i]=1<<30; 
    priority_queue<Edge,vector<Edge>,greater<Edge>> que;
    que.push(Edge(0,s));
    while(!que.empty()){
        Edge e=que.top(); que.pop();
        if(e.cost>=cost[e.to]) continue;
        cost[e.to]=e.cost;
        for(auto next:G[e.to]) que.push(Edge(next.to,e.cost+next.cost));
    }
}

ll N,M;
vector<vector<Edge>> GS,GW,GG;
ll a,b,s,w;

ll f(vector<vector<Edge>> &G, vector<ll> &cost, vector<ll> &memo, ll p){
    if(p==0) return 1;
    if(memo[p]!=LINF) return memo[p];
    ll res=0;
    repr(e,G[p]){
        if(cost[p]-e.cost==cost[e.to]){
            res+=f(G,cost,memo,e.to);
        }
    }
    memo[p]=res;
    return res;
}

int main(){
    cin>>N>>M;
    GS=vector<vector<Edge>>(N,vector<Edge>(0));
    GW=vector<vector<Edge>>(N,vector<Edge>(0));
    GG=vector<vector<Edge>>(N,vector<Edge>(0));
    rep(i,M){
        cin>>a>>b>>s>>w;
        a--, b--;
        GS[a].push_back(Edge(b,s));
        GW[a].push_back(Edge(b,w));
        GG[a].push_back(Edge(b,s+w));
        GS[b].push_back(Edge(a,s));
        GW[b].push_back(Edge(a,w));
        GG[b].push_back(Edge(a,s+w));
    }

    vector<ll> cost(N),memo(N);
    ll ans=0;
    ll sum=0;

    fill(memo.begin(),memo.end(),LINF);
    dijkstra(GS,cost,0);
    // rep(i,N) cout<<i+1<<": "<<cost[i]<<endl;
    ans+=f(GS,cost,memo,N-1);
    sum+=cost[N-1];
    cout<<ans<<endl;

    fill(memo.begin(),memo.end(),LINF);
    dijkstra(GW,cost,0);
    // rep(i,N) cout<<i+1<<": "<<cost[i]<<endl;
    ans+=f(GW,cost,memo,N-1);
    sum+=cost[N-1];
    cout<<ans<<endl;

    fill(memo.begin(),memo.end(),LINF);
    dijkstra(GG,cost,0);
    // rep(i,N) cout<<i+1<<": "<<cost[i]<<endl;
    if(cost[N-1]==sum) ans-=f(GG,cost,memo,N-1);

    cout<<ans<<endl;
    
    return 0;
}