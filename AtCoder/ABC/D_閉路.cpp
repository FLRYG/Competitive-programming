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

int N;

int main(){
    cin>>N;
    vector<vector<int>> G(N,vector<int>());
    rep(i,N-1){
        int x,y;
        cin>>x>>y;
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    LCA lca(G);
    int Q;
    cin>>Q;
    vector<int> ans(Q);
    rep(q,Q){
        int a,b;
        cin>>a>>b;
        a--, b--;
        int c=lca.query(a,b);
        ans[q]=lca.depth(a)+lca.depth(b)-2*lca.depth(c)+1;
    }

    repr(e,ans) cout<<e<<endl;
    
    return 0;
}





// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <list>
// #include <iomanip>
// #include <stack>
// #include <queue>
// #include <deque>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <bitset>
// #include <chrono>
// #include <random>
// #define rep(i,n) for(int i=0;i<n;i++)
// #define repn(i,n) for(int i=1;i<=n;i++)
// #define repr(e,x) for(auto& e:x)
// using namespace std;
// typedef long long ll;
// typedef long double ld;
// typedef pair<int,int> P;
// // typedef pair<int,P> IP;
// // typedef pair<P,P> PP;
// double const PI=3.141592653589793;
// int const INF=1001001001;
// ll const LINF=1001001001001001001;
// ll const MOD=1000000007;

// template<class T, T (*op)(T ,T), T (*e)()> struct segmentTree{
//     int n;
//     std::vector<T> v;
//     segmentTree() : segmentTree(0){}
//     segmentTree(int _n){
//         n=1;
//         while(n<_n) n*=2;
//         v=std::vector<T>(2*n-1,e());
//     }
//     ~segmentTree(){}
//     void set(int k, T a){
//         k+=n-1;
//         v[k]=a;
//         while(k>0){
//             k=(k-1)/2;
//             v[k]=op(v[k*2+1],v[k*2+2]);
//         }
//     }
//     T get(int k){return v[k+n-1];}
//     const T& operator[](std::size_t n) const& { return v[n]; }
//     T& operator[](std::size_t n) & { return v[n]; }
//     T query(int l, int r){return query(l,r,0,0,n);}     // [l,r) 半開区間に注意
//     T query(int l, int r, int k, int a, int b){
//         if(b<=l || r<=a) return e();
//         if(l<=a && b<=r) return v[k];
//         T vl=query(l,r,k*2+1,a,(a+b)/2);
//         T vr=query(l,r,k*2+2,(a+b)/2,b);
//         return op(vl,vr);
//     }
// };
// P op(P a, P b){
//     if(a.first<b.first) return a;
//     else return b;
// }
// P e(){ return {INF,0}; }

// int N;
// vector<vector<int>> G;
// vector<int> vs;
// vector<int> depth;
// vector<int> id;

// void dfs(int x, int d, int &k, int prev){
//     id[x]=k;
//     vs[k]=x;
//     depth[k++]=d;
//     repr(e,G[x]){
//         if(e==prev) continue;
//         dfs(e,d+1,k,x);
//         vs[k]=x;
//         depth[k++]=d;
//     }
// }

// int main(){
//     cin>>N;
//     G.resize(N,vector<int>());
//     rep(i,N-1){
//         int x,y;
//         cin>>x>>y;
//         x--, y--;
//         G[x].push_back(y);
//         G[y].push_back(x);
//     }

//     vs.resize(2*N-1,-1);
//     depth.resize(2*N-1,-1);
//     id.resize(N,-1);
//     int k=0;
//     dfs(0,0,k,-1);
//     rep(i,2*N-1) cout<<vs[i]+1<<' '; cout<<endl;
//     rep(i,2*N-1) cout<<depth[i]<<' '; cout<<endl;
//     rep(i,N) cout<<i+1<<' '<<id[i]<<endl;
    
//     segmentTree<P,op,e> st(2*N-1);
//     rep(i,2*N-1) st[i]={depth[i],vs[i]};

//     int Q;
//     cin>>Q;
//     while(Q--){
//         int a,b;
//         cin>>a>>b;
//         a--, b--;
//         a=id[a];
//         b=id[b];
//         if(a>b) swap(a,b);
//         cout<<a<<' '<<b<<endl;
//         int v=st.query(a,b+1).second;
//         cout<<st.query(a,b+1).first<<' '<<v<<endl;
//         int ans=depth[a]+depth[b]-depth[id[v]]+1;
//         cout<<ans<<endl;
//     }
    
//     return 0;
// }