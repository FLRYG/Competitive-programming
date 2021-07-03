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

int const I[]={1,0,-1,0};
int const J[]={0,1,0,-1};

int H,W;
int A[50][50];

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

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>A[i][j];
    vector<vector<Edge>> G(H*W);
    rep(i,H) rep(j,W) rep(k,4){
        int x=i+I[k];
        int y=j+J[k];
        if(0<=x && x<H && 0<=y && y<W){
            G[i*W+j].push_back(Edge(x*W+y,A[x][y]));
        }
    }

    vector<int> X,Y,Z;
    dijkstra(G,X,(H-1)*W);
    dijkstra(G,Y,(H-1)*W+W-1);
    dijkstra(G,Z,W-1);

    int ans=INF;
    rep(i,H) rep(j,W){
        int res=0;
        res+=X[i*W+j];
        res+=Y[i*W+j];
        res+=Z[i*W+j];
        res-=2*A[i][j];
        ans=min(ans,res);
    }

    cout<<ans<<endl;

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
// typedef pair<int,P> IP;
// // typedef pair<P,P> PP;
// double const PI=3.141592653589793;
// int const INF=1001001001;
// ll const LINF=1001001001001001001;
// ll const MOD=1000000007;

// int const I[]={1,0,-1,0};
// int const J[]={0,1,0,-1};

// int H,W;
// int A[50][50];

// typedef pair<IP,int> IPC;

// void f(P s, /*P g,*/ vector<vector<int>> &from){
//     vector<vector<int>> chk(H,vector<int>(W,0));
//     priority_queue<IPC,vector<IPC>,greater<IPC>> q;
//     q.push({{0,s},-1});
//     while(!q.empty()){
//         IPC ipc=q.top(); q.pop();
//         int c=ipc.first.first;
//         int i=ipc.first.second.first, j=ipc.first.second.second;
//         int d=ipc.second;
//         if(chk[i][j]) continue;
//         chk[i][j]=1;
//         from[i][j]=d;
//         // if(i==g.first && j==g.second) break;
//         rep(k,4){
//             int x=i+I[k];
//             int y=j+J[k];
//             if(0<=x && x<H && 0<=y && y<W && chk[x][y]==0){
//                 q.push({{c+A[x][y],{x,y}},(k+2)%4});
//             }
//         }
//     }
//     // repr(v,from){repr(e,v) cout<<e; cout<<endl;} cout<<endl;
//     // while(s.first!=g.first || s.second!=g.second){
//     //     res[g.first][g.second]=1;
//     //     int x=g.first, y=g.second;
//     //     g.first+=I[from[x][y]];
//     //     g.second+=J[from[x][y]];
//     // }
// }

// int main(){
//     cin>>H>>W;
//     rep(i,H) rep(j,W) cin>>A[i][j];

//     int ans=INF;
//     rep(i,H) rep(j,W){
//         vector<vector<int>> from(H,vector<int>(W,-1));
//         f({i,j},from);
//         int cost=A[i][j], x, y;
//         vector<vector<int>> chk(H,vector<int>(W,1));
//         chk[i][j]=0;
//         x=H-1, y=0;
//         while(x!=i || y!=j){
//             // cout<<x<<' '<<y<<endl;
//             if(chk[x][y]){
//                 cost+=A[x][y];
//                 chk[x][y]=0;
//             }
//             int xx=x, yy=y;
//             x+=I[from[xx][yy]];
//             y+=J[from[xx][yy]];
//         }
//         x=H-1, y=W-1;
//         while(x!=i || y!=j){
//             if(chk[x][y]){
//                 cost+=A[x][y];
//                 chk[x][y]=0;
//             }
//             int xx=x, yy=y;
//             x+=I[from[xx][yy]];
//             y+=J[from[xx][yy]];
//         }
//         x=0, y=W-1;
//         while(x!=i || y!=j){
//             if(chk[x][y]){
//                 cost+=A[x][y];
//                 chk[x][y]=0;
//             }
//             int xx=x, yy=y;
//             x+=I[from[xx][yy]];
//             y+=J[from[xx][yy]];
//         }
//         ans=min(ans,cost);
//     }

//     cout<<ans<<endl;
    
//     return 0;
// }