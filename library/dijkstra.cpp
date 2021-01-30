#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra(vector<vector<int>> &G, vector<int> &cost, int s){
    for(auto &e:cost) e=1<<30; 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(pair<int,int>(0,s));
    while(!q.empty()){
        pair<int,int> p=q.top(); q.pop();
        if(p.first>=cost[p.second]) continue;
        cost[p.second]=p.first;
        for(auto &e:G[p.second]){
            q.push(pair<int,int>(p.first+1,e));
        }
    }
}

int main(){
    int N=7;
    vector<vector<int>> G(N,vector<int>());
}