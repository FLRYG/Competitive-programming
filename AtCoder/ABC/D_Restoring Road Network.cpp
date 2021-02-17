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
typedef pair<ll,ll> P;
double const PI=3.141592653589793;
int const INF=2147483647;
ll const LINF=9223372036854775807;
ll const MOD=1000000007;

ll N;
ll A[300][300];

int main(){
    cin>>N;
    rep(i,N) rep(j,N) cin>>A[i][j];

    rep(i,N){
        rep(j,N){
            rep(k,N){
                if(A[i][j]>A[i][k]+A[k][j]){
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
    }

    ll ans=0;
    rep(i,N) rep(j,N) ans+=A[i][j];

    rep(i,N){
        rep(j,N){
            bool b=false;
            rep(k,N){
                if(k==i || k==j) continue;
                b|=A[i][j]==A[i][k]+A[k][j];
            }
            if(b) ans-=A[i][j];
        }
    }
    ans/=2;

    cout<<ans<<endl;

    return 0;
}

// struct Edge{
//     ll to,cost;
//     Edge(): to(0), cost(0) {}
//     Edge(const ll &_to, const ll &_cost): to(_to), cost(_cost) {}
//     bool operator<(const Edge &e) const{ return cost < e.cost; }
//     bool operator>(const Edge &e) const{ return cost > e.cost; }
//     bool operator<=(const Edge &e) const{ return !(cost > e.cost); }
//     bool operator>=(const Edge &e) const{ return !(cost < e.cost); }
// };

// void dijkstra(vector<vector<Edge>> &G, vector<ll> &cost, ll s){
//     for(ll i=0;i<cost.size();i++) cost[i]=1LL<<60; 
//     priority_queue<Edge,vector<Edge>,greater<Edge>> que;
//     que.push(Edge(s,0));
//     while(!que.empty()){
//         Edge e=que.top(); que.pop();
//         if(e.cost>=cost[e.to]) continue;
//         cost[e.to]=e.cost;
//         for(auto next:G[e.to]) que.push(Edge(next.to,e.cost+next.cost));
//     }
// }

// struct unionFind{
//     int* par;                       //親
//     int* rank;                      //木の深さ
//     int* scale;                     //木のサイズ
//     int quantity;                   //木の個数
//     unionFind(int n);
//     ~unionFind();
//     int find(int x);                //木の根を求める
//     void unite(int x,int y);        //xとyの属する集合を併合
//     bool same(int x,int y);         //xとyが同じ集合に属するか否か
//     int size(int x);                //xの属する集合のサイズ
//     int count();                    //木の個数
// };

// unionFind::unionFind(int n){
//     par=new int[n];
//     rank=new int[n];
//     scale=new int[n];
//     quantity=n;
//     for(int i=0;i<n;i++){
//         par[i]=i;
//         rank[i]=0;
//         scale[i]=1;
//     }
// }

// unionFind::~unionFind(){
//     delete[] par;
//     delete[] rank;
//     delete[] scale;
// }

// int unionFind::find(int x){
//     if(par[x]==x) return x;
//     return par[x]=find(par[x]);
// }

// void unionFind::unite(int x,int y){
//     x=find(x);
//     y=find(y);
//     if(x==y) return;
//     quantity--;
//     if(rank[x]<rank[y]){
//         par[x]=y;
//         scale[y]+=scale[x];
//     }else{
//         par[y]=x;
//         scale[x]+=scale[y];
//         if(rank[x]==rank[y]) rank[x]++;
//     }
// }

// bool unionFind::same(int x,int y){
//     return find(x)==find(y);
// }

// int unionFind::size(int x){
//     x=find(x);
//     return scale[x];
// }

// int unionFind::count(){
//     return quantity;
// }

// ll N;
// ll A[300][300];

// int main(){
//     cin>>N;
//     rep(i,N) rep(j,N) cin>>A[i][j];
//     // vector<vector<Edge>> G(N,vector<Edge>(N));
//     // rep(i,N) rep(j,N){
//     //     cin>>A[i][j];
//     //     G[i][j]=Edge(j,A[i][j]);
//     // }

//     // vector<vector<ll>> cost(N,vector<ll>(N));
//     // rep(i,N) dijkstra(G,cost[i],i);
//     // rep(i,N){ rep(j,N){ cout<<cost[i][j]<<' '; } cout<<endl; }

//     // rep(i,N) rep(j,N){
//     //     if(cost[i][j]!=A[i][j]){
//     //         cout<<-1<<endl;
//     //         return 0;
//     //     }
//     // }

//     ll ans=0;
//     vector<pair<ll,P>> v(N*N);
//     rep(i,N) rep(j,N){
//         v[i*N+j]=pair<ll,P>(A[i][j],P(i,j));
//     }
//     sort(v.begin(),v.end());
//     unionFind uf(N);
//     vector<vector<Edge>> G(N,vector<Edge>(0));
//     repr(e,v){
//         cout<<e.first<<' '<<e.second.first<<' '<<e.second.second<<endl;
//         if(!uf.same(e.second.first,e.second.second)){
//             ans+=e.first;
//             uf.unite(e.second.first,e.second.second);
//             G[e.second.first].push_back(Edge(e.second.second,e.first));
//             G[e.second.second].push_back(Edge(e.second.first,e.first));
//         }
//     }

//     vector<vector<ll>> cost(N,vector<ll>(N));
//     rep(i,N) dijkstra(G,cost[i],i);

//     rep(i,N){
//         rep(j,N){
//             if(cost[i][j]<A[i][j]){
//                 cout<<-1<<endl;
//                 return 0;
//             }else if(cost[i][j]>A[i][j]){

//             }
//         }
//     }

//     cout<<ans<<endl;
    
//     return 0;
// }

// ll N;
// ll A[300][300];

// int main(){
//     cin>>N;
//     vector<vector<Edge>> G(N,vector<Edge>(N));
//     rep(i,N) rep(j,N){
//         cin>>A[i][j];
//         G[i][j]=Edge(j,A[i][j]);
//     }

//     vector<vector<ll>> cost(N,vector<ll>(N));
//     rep(i,N) dijkstra(G,cost[i],i);
//     rep(i,N){ rep(j,N){ cout<<cost[i][j]<<' '; } cout<<endl; }

//     rep(i,N) rep(j,N){
//         if(cost[i][j]!=A[i][j]){
//             cout<<-1<<endl;
//             return 0;
//         }
//     }

//     ll ans=0;
//     vector<pair<ll,P>> v(N*N);
//     rep(i,N) rep(j,N) v[i*N+j]=pair<ll,P>(A[i][j],P(i,j));
//     sort(v.begin(),v.end());
//     unionFind uf(N);
//     repr(e,v){
//         cout<<e.first<<' '<<e.second.first<<' '<<e.second.second<<endl;
//         if(!uf.same(e.second.first,e.second.second)){
//             ans+=e.first;
//             uf.unite(e.second.first,e.second.second);
//         }
//     }

//     cout<<ans<<endl;
    
//     return 0;
// }