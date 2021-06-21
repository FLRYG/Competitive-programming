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
    Edge(ll _to, const ll _cost): to(_to), cost(_cost){}
    bool operator<(const Edge &e) const{ return cost < e.cost; }
    bool operator>(const Edge &e) const{ return cost > e.cost; }
    bool operator<=(const Edge &e) const{ return !(cost > e.cost); }
    bool operator>=(const Edge &e) const{ return !(cost < e.cost); }
};

void dijkstra(vector<vector<Edge>> &G, vector<int> &cost, int s){
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

ll M,R;

int main(){
    cin>>M>>R;

    vector<vector<Edge>> G(10*M,vector<Edge>(0));
    G[0].push_back(Edge(1,1));
    G[1].push_back(Edge(0,1));
    rep(i,3) repn(j,2){
        G[i*3+j].push_back(Edge(i*3+j+1,1));
        G[i*3+j+1].push_back(Edge(i*3+j,1));
    }
    rep(i,2) repn(j,3){
        G[i*3+j].push_back(Edge((i+1)*3+j,1));
        G[(i+1)*3+j].push_back(Edge(i*3+j,1));
    }

    vector<vector<int>> cost(10,vector<int>());
    rep(i,10) dijkstra(G,cost[i],i);

    ll ans=LINF;
    rep(i,10*M+1){
        string N=to_string(M*i+R);
        ll pos=0, res=0;
        rep(i,N.size()){
            int next=N[i]-'0';
            res+=cost[pos][next]+1;
            pos=next;
        }
        ans=min(ans,res);
    }

    cout<<ans<<endl;
    
    return 0;
}