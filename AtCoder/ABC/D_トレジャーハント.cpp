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
    ll to,cost;
    Edge(): to(0), cost(0) {}
    Edge(ll _to, const ll _cost): to(_to), cost(_cost){}
    bool operator<(const Edge &e) const{ return cost < e.cost; }
    bool operator>(const Edge &e) const{ return cost > e.cost; }
    bool operator<=(const Edge &e) const{ return !(cost > e.cost); }
    bool operator>=(const Edge &e) const{ return !(cost < e.cost); }
};

void dijkstra(vector<vector<Edge>> &G, vector<ll> &cost, ll s){
    cost.assign(G.size(),INF);
    priority_queue<Edge,vector<Edge>,greater<Edge>> que;
    que.push(Edge(s,0));
    while(!que.empty()){
        Edge e=que.top(); que.pop();
        if(e.cost>=cost[e.to]) continue;
        cost[e.to]=e.cost;
        for(auto next:G[e.to]) que.push(Edge(next.to,e.cost+next.cost));
    }
}

ll N,M,T;
ll A[100000];

int main(){
    cin>>N>>M>>T;
    rep(i,N) cin>>A[i];
    vector<vector<Edge>> G1(N);
    vector<vector<Edge>> G2(N);
    rep(i,M){
        ll a,b,c;
        cin>>a>>b>>c;
        a--, b--;
        G1[a].push_back(Edge(b,c));
        G2[b].push_back(Edge(a,c));
    }

    vector<ll> cost1, cost2;
    dijkstra(G1,cost1,0);
    dijkstra(G2,cost2,0);

    ll ans=0;
    rep(i,N){
        ans=max(ans,A[i]*(T-cost1[i]-cost2[i]));
    }

    cout<<ans<<endl;
    
    return 0;
}