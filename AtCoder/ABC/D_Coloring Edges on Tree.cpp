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
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

struct Edge{
    int color,id;
    Edge(int color=0,int id=0)
        :color(color),id(id){}
};

int N;
map<int,Edge> G[100001];
int ans[100001];

void bfs(int from,int parent,int NG){
    int c=1;
    for(auto& e:G[from]){
        if(e.first==parent) continue;
        if(c==NG) c++;
        e.second.color=c;
        G[e.first][from].color=c;
        ans[e.second.id]=c;
        c++;
    }
    for(auto& e:G[from]){
        if(e.first==parent) continue;
        bfs(e.first,from,e.second.color);
    }
}

int main(){
    cin>>N;
    repn(i,N-1){
        int a,b;
        cin>>a>>b;
        G[a][b]=Edge(0,i);
        G[b][a]=Edge(0,i);
    }

    int K=0;
    repn(i,N) K=max(K,(int)G[i].size());

    bfs(1,0,0);

    cout<<K<<endl;
    repn(i,N-1) cout<<ans[i]<<endl;
}

/*typedef pair<int,int> P;

int N;
map<int,P> G[100001];
int ans[100001];

void bfs(int from,int parent){
    int NG=0;
    if(parent!=0) NG=G[from][parent].second;
    int c=1;
    //cout<<"from:"<<from<<" parent:"<<parent<<" NG:"<<NG<<endl;
    if(G[from].size()==1 && NG!=0) return;
    for(auto& e:G[from]){
        //cout<<' '<<from<<'-'<<e.first<<' ';
        if(c==NG || G[from][e.first].second!=0){
            //cout<<"NG"<<endl;
            if(c==NG) c++;
            continue;
        }
        G[from][e.first].second=c;
        G[e.first][from].second=c;
        ans[e.second.first]=c;
        //cout<<"color: "<<c<<endl;
        c++;
    }
    for(auto& e:G[from]){
        if(e.first==parent) continue;
        bfs(e.first,from);
    }
}

int main(){
    cin>>N;
    repn(i,N-1){
        int a,b;
        cin>>a>>b;
        G[a][b]=P(i,0);
        G[b][a]=P(i,0);
    }

    int K=0;
    repn(i,N){
        K=max(K,(int)G[i].size());
    }
    cout<<K<<endl;

    bfs(1,0);

    repn(i,N-1){
        cout<<ans[i]<<endl;
    }
}*/