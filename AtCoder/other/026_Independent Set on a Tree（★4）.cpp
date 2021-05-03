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

void dfs(int v, int p, vector<vector<int>> &G, vector<int> &col, vector<int> &cnt){
    col[v]=!col[p];
    cnt[col[v]]++;
    repr(e,G[v]){
        if(e!=p) dfs(e,v,G,col,cnt);
    }
}

int N;

int main(){
    cin>>N;
    vector<vector<int>> G(N,vector<int>(0));
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> cnt(2,0);
    vector<int> col(N,0);
    dfs(0,-1,G,col,cnt);

    int k=cnt[0]<=cnt[1];
    vector<int> ans(0);
    rep(i,N) if(col[i]==k) ans.push_back(i+1);

    rep(i,N/2) cout<<ans[i]<<' '; cout<<endl;

    return 0;
}