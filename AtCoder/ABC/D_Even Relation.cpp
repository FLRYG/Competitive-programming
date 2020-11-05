#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

struct Edge{
    int from,to;
    ll d;
    Edge(int from,int to,ll d)
    :from(from),to(to),d(d){}
};

int N;
vector<Edge> G[100001];
ll dis[100001];

void dfs(int from,ll d,int parent){
    rep(i,G[from].size()){
        if(parent!=G[from][i].to){
            ll next=dis[G[from][i].to]=G[from][i].d+d;
            dfs(G[from][i].to,next,from);
        }
    }
}

int main(){
    cin>>N;
    rep(i,N-1){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(Edge(u,v,w));
        G[v].push_back(Edge(v,u,w));
    }

    dfs(1,0,-1);

    repn(i,N){
        int ans=dis[i]&1;
        cout<<ans<<endl;
    }
}