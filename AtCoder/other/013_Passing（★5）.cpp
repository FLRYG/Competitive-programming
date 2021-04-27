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
    int to,cost;
    Edge(): to(0), cost(0) {}
    Edge(const int &_to, const int &_cost)
    : to(_to), cost(_cost)
    {}
    bool operator<(const Edge &e) const{ return cost < e.cost; }
    bool operator>(const Edge &e) const{ return cost > e.cost; }
    bool operator<=(const Edge &e) const{ return !(cost > e.cost); }
    bool operator>=(const Edge &e) const{ return !(cost < e.cost); }
};

void dijkstra(vector<vector<Edge>> &G, vector<int> &cost, int s){
    cost.resize(G.size());
    for(int i=0;i<cost.size();i++) cost[i]=INF; 
    priority_queue<Edge,vector<Edge>,greater<Edge>> que;
    que.push(Edge(s,0));
    while(!que.empty()){
        Edge e=que.top(); que.pop();
        if(e.cost>=cost[e.to]) continue;
        cost[e.to]=e.cost;
        for(auto next:G[e.to]) que.push(Edge(next.to,e.cost+next.cost));
    }
}

int N,M;

int main(){
    cin>>N>>M;
    vector<vector<Edge>> G(N,vector<Edge>(0));
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--, b--;
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
    }

    vector<int> cost1;
    vector<int> costN;
    dijkstra(G,cost1,0);
    dijkstra(G,costN,N-1);

    rep(i,N){
        int ans=cost1[i]+costN[i];
        cout<<ans<<endl;
    }
    
    return 0;
}