#include <iostream>
#include <vector>
using namespace std;

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

int main(){
    
    
    return 0;
}