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

struct LCA{
    int V;
    int logV;
    vector<vector<int>> G;
    int root;
    vector<vector<int>> parent;
    vector<int> depthv;
    LCA(vector<vector<int>> const &_G, int _root=0): G(_G), root(_root) {
        V=G.size();
        logV=0;
        int size=1; 
        while(size<V) logV++, size*=2;
        parent.resize(logV);
        for(int i=0; i<logV; i++) parent[i].resize(V);
        depthv.resize(V);

        dfs(root,-1,0);

        for(int k=0; k+1<logV; k++){
            for(int v=0; v<V; v++){
                if(parent[k][v]<0) parent[k+1][v]=-1;
                else parent[k+1][v]=parent[k][parent[k][v]];
            }
        }
    }
    void dfs(int v, int p, int d){
        parent[0][v]=p;
        depthv[v]=d;
        for(int i=0; i<G[v].size(); i++){
            if(G[v][i]!=p) dfs(G[v][i],v,d+1);
        }
    }
    int query(int u, int v){
        if(depthv[u]>depthv[v]) swap(u,v);
        for(int k=0; k<logV; k++){
            if((depthv[v]-depthv[u])>>k&1) v=parent[k][v];   
        }
        if(u==v) return u;
        for(int k=logV-1; k>=0; k--){
            if(parent[k][u]!=parent[k][v]){
                u=parent[k][u];
                v=parent[k][v];
            }
        }
        return parent[0][u];
    }
    int depth(int k){ return depthv[k]; }
};

int N,Q;

int main(){
    cin>>N>>Q;
    vector<vector<int>> G(N);
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    LCA lca(G);
    while(Q--){
        int c,d;
        cin>>c>>d;
        c--, d--;
        int len=lca.depth(c)+lca.depth(d)-2*lca.depth(lca.query(c,d));
        // cout<<lca.depth(c)<<lca.depth(d)<<lca.depth(lca.query(c,d))<<endl;
        string ans="Town";
        if(len&1) ans="Road";
        cout<<ans<<endl;
    }
    
    return 0;
}