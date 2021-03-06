#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int INF=1001001001;

struct Edge{
    int to,cost;
    Edge(): to(0), cost(0) {}
    Edge(int _to, int _cost): to(_to), cost(_cost){}
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
    // N: 頂点の数
    // M: 辺の数
    int N,M;
    cin>>N>>M;
    vector<vector<Edge>> G(N,vector<Edge>(N));
    for(int i=0;i<M;i++){
        int v1,v2,cost;
        cin>>v1>>v2>>cost;
        G[v1].push_back(Edge(v2,cost));
        G[v2].push_back(Edge(v1,cost));
    }

    vector<int> cost(N);
    dijkstra(G,cost,0);

    for(int i=0;i<N;i++) cout<<i<<": "<<cost[i]<<endl;

    return 0;
}

// void dijkstra(vector<vector<int>> &G, vector<int> &cost, int s){
//     for(auto &e:cost) e=1<<30; 
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
//     q.push(pair<int,int>(0,s));
//     while(!q.empty()){
//         pair<int,int> p=q.top(); q.pop();
//         if(p.first>=cost[p.second]) continue;
//         cost[p.second]=p.first;
//         for(auto &e:G[p.second]){
//             q.push(pair<int,int>(p.first+1,e));
//         }
//     }
// }

// int main(){
//     int nodeN, edgeN;
//     vector<vector<int>> G(nodeN,vector<int>());
//     cin>>nodeN>>edgeN;
//     for(int i=0;i<edgeN;i++){
//         int a,b;
//         cin>>a>>b;
//         G[a].push_back(b);
//         G[b].push_back(a);
//     }

//     vector<int> cost(nodeN,0);
//     dijkstra(G,cost,0);

// }