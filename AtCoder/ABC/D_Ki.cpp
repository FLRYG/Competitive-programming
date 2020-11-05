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

int N,Q;
vector<int> G[200001];
int X[200001];
int ans[200000];

void dfs(int from,int parent,int cnt){
    ans[from]=X[from]+cnt;
    rep(i,G[from].size()){
        if(G[from][i]!=parent){
            dfs(G[from][i],from,X[from]+cnt);
        }
    }
}

int main(){
    cin>>N>>Q;
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,Q){
        int p,x;
        cin>>p>>x;
        X[p]+=x;
    }

    dfs(1,0,0);

    repn(i,N){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}