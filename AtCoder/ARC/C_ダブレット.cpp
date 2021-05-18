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

string fst, lst;
int N;
string S[1002];

void dfs(int v, vector<vector<Edge>> &G, vector<int> &cost, vector<string> &ans){
    ans.push_back(S[v]);
    repr(e,G[v]){
        if(cost[e.to]+1==cost[v]){
            dfs(e.to,G,cost,ans);
            break;
        }
    }
}

int main(){
    cin>>fst>>lst>>N;
    rep(i,N) cin>>S[i];
    S[N]=fst;
    S[N+1]=lst;

    map<string,vector<int>> m;
    rep(i,N+2) m[S[i]].push_back(i);
    set<string> st;
    rep(i,N+2) st.insert(S[i]);


    vector<vector<Edge>> G(N+2,vector<Edge>(0));
    rep(i,N+2){
        string t=S[i];
        rep(j,S[i].size()){
            rep(k,26){
                t[j]='a'+k;
                if(st.find(t)!=st.end()){
                    repr(e,m[t]){
                        G[i].push_back(Edge(e,1));
                        G[e].push_back(Edge(i,1));
                    }
                }
            }
            t[j]=S[i][j];
        }
    }

    vector<int> cost(N+2,0);
    dijkstra(G,cost,N);
    if(cost[N+1]==INF){
        cout<<-1<<endl;
        return 0;
    }

    vector<string> ans;
    dfs(N+1,G,cost,ans);

    reverse(ans.begin(),ans.end());
    cout<<ans.size()-2<<endl;
    repr(e,ans) cout<<e<<endl;
    
    return 0;
}