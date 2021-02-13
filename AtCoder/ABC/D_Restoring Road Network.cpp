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
int const INF=2147483647;
ll const LINF=9223372036854775807;
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

ll N;
ll A[300][300];

int main(){
    cin>>N;
    vector<vector<Edge>> G(N,vector<Edge>(N));
    rep(i,N) rep(j,N){
        cin>>A[i][j];
        G[i][j]=Edge(j,A[i][j]);
    }

    vector<vector<ll>> cost(N,vector<ll>(N));
    rep(i,N) dijkstra(G,cost[i],i);

    rep(i,N) rep(j,N){
        if(cost[i][j]!=A[i][j]){
            cout<<-1<<endl;
            return 0;
        }
    }

    
    
    return 0;
}