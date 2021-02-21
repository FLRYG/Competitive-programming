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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
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

int N,M,K;
int A[100000];
int B[100000];
int C[17];

int main(){
    cin>>N>>M;
    vector<vector<Edge>> G(N,vector<Edge>());
    rep(i,M){
        int a,b;
        cin>>a>>b;
        G[a-1].push_back(Edge(b-1,1));
        G[b-1].push_back(Edge(a-1,1));
    }
    cin>>K;
    rep(i,K){
        cin>>C[i];
        C[i]--;
    }

    vector<vector<int>> cost(K,vector<int>(N));
    rep(i,K) dijkstra(G,cost[i],C[i]);
    rep(i,K){
        bool b=false;
        rep(j,K){
            if(i==j) continue;
            b|=cost[i][C[j]]==INF?false:true;
        }
        if(!b){
            cout<<-1<<endl;
            return 0;
        }
    }
    // rep(i,K){
    //     rep(j,N) cout<<cost[i][j]<<' '; cout<<endl;
    // }


    vector<vector<int>> dp(1<<K,vector<int>(K,INF));
    rep(i,K) dp[(1<<K)-1-(1<<i)][i]=1;
    for(int i=(1<<K)-1;i>=0;i--){
        rep(j,K){
            rep(k,K){
                dp[i][j]=min(dp[i][j],dp[i|1<<j][k]+cost[j][C[k]]);
            }
        }
    }
    int ans=INF;
    // for(int i=(1<<K)-1;i>=0;i--) rep(j,K) cout<<bitset<4>(i)<<' '<<dp[i][j]<<endl;
    rep(i,K) ans=min(ans,dp[0][i]);

    cout<<ans<<endl; 

    return 0;
}

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

// void dijkstra(vector<vector<int>> &G, vector<int> &cost, int s){
//     priority_queue<P,vector<P>,greater<P>> q;
//     cost[s]=1;
//     q.push(P(1,s));
//     while(!q.empty()){
//         P p=q.top(); q.pop();
//         if(p.first>=cost[p.second]) continue;
//         cost[p.second]=p.first;
//         repr(e,G[p.second]){
//             q.push(P(p.first+1,e));
//         }
//     }
// }

// int N,M,K;
// int C[17]; 

// int main(){
//     cin>>N>>M>>K;
//     unionFind uf(N);
//     vector<vector<int>> G(M,vector<int>());
//     rep(i,M){
//         int a,b;
//         cin>>a>>b;
//         G[a-1].push_back(b-1);
//         G[b-1].push_back(a-1);
//         uf.unite(a-1,b-1);
//     }
//     cin>>K;
//     rep(i,K) cin>>C[i];

//     rep(i,K){
//         if(!uf.same(C[0],C[i])){
//             cout<<-1<<endl;
//             return 0;
//         }
//     }

//     vector<vector<int>> cost(K,vector<int>(K,INF));
//     rep(i,K) dijkstra(G,cost[i],i);

//     int ans=0;
//     rep(s,K){
//         vector<int> chk(K,0);
//         int res=1;
//         chk[s]=1;
//         int ss=s;
//     }
    
//     return 0;
// }