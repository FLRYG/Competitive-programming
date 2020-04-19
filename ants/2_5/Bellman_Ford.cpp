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

const int INF=100100100;
struct edge{int from,to,cost;};

int V,E,S;
edge es[2000];
int d[1000];

//頂点Sから各頂点への最短距離
int main(){
    cin>>V>>E>>S;
    rep(i,E){
        int from,to,cost;
        cin>>from>>to>>cost;
        es[2*i].from=from;
        es[2*i].to=to;
        es[2*i].cost=cost;
        es[2*i+1].from=to;
        es[2*i+1].to=from;
        es[2*i+1].cost=cost;
    }

    rep(i,V) d[i]=INF;
    d[S-1]=0;
    while(true){
        bool update=false;
        rep(i,2*E){
            edge e=es[i];
            if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                update=true;
            }
        }
        if(!update) break;
    }

    rep(i,V) cout<<d[i]<<endl;
}