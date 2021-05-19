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

template<class T>T gcd(T a, T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a/gcd(a,b)*b;}

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

int N,M,R,T;

int main(){
    cin>>N>>M>>R>>T;
    int g=gcd(R,T);
    vector<vector<Edge>> GR(N,vector<Edge>());
    vector<vector<Edge>> GT(N,vector<Edge>());
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--, b--;
        GR[a].push_back(Edge(b,c*T));
        GR[b].push_back(Edge(a,c*T));
        GT[a].push_back(Edge(b,c*R));
        GT[b].push_back(Edge(a,c*R));
    }

    ll ans=0;
    rep(s,N){
        vector<int> costR(N,0);
        vector<int> costT(N,0);
        dijkstra(GR,costR,s);
        dijkstra(GT,costT,s);
        // cout<<s<<':'<<endl;
        // cout<<"  R: "; rep(i,N) cout<<costR[i]<<' '; cout<<endl; 
        // cout<<"  T: "; rep(i,N) cout<<costT[i]<<' '; cout<<endl; 
        vector<int> cR=costR;
        vector<int> cT=costT;
        sort(cR.begin(),cR.end());
        sort(cT.begin(),cT.end());
        // cout<<"  R: "; rep(i,N) cout<<cR[i]<<' '; cout<<endl; 
        // cout<<"  T: "; rep(i,N) cout<<cT[i]<<' '; cout<<endl; 
        ll t=1;
        repn(r,N-1){
            while(cT[t]<cR[r] && t<N) t++;
            // cout<<t-1<<endl;
            ans+=t-1;
            if(costT[r]<costR[r]) ans--;
        }
    }
    
    cout<<ans<<endl;

    return 0;
}