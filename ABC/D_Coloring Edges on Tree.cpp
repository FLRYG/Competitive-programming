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

typedef pair<int,int> P;

int N;
map<int,P> G[100001];
int ans[100001];

void dfs(int from,int parent){
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
        dfs(e.first,from);
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

    dfs(1,0);

    repn(i,N-1){
        cout<<ans[i]<<endl;
    }
}