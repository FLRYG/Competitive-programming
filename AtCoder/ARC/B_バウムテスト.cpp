#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;

int N,M;
vector<int> G[101];
bool act[101];

bool dfs(int x, int parent){
    if(act[x]) return false;
    act[x]=true;
    bool res=true;
    repr(e,G[x]){
        if(e==parent) continue;
        res&=dfs(e,x);
        if(!res) break;
    }
    return res;
}

int main(){
    cin>>N>>M;
    rep(i,M){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans=0;
    repn(i,N){
        if(dfs(i,0)) ans++;
    }

    cout<<ans<<endl;
}