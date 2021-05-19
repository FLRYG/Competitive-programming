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
typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;

P dfs(int v, int p, int d, vector<vector<int>> &G){
    P res={d,v};
    repr(e,G[v]) if(e!=p) res=max(res,dfs(e,v,d+1,G));
    return res;
}

int main(){
    cin>>N;
    vector<vector<int>> G(N,vector<int>());
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans1=dfs(0,-1,0,G).second;
    int ans2=dfs(ans1,-1,0,G).second;

    cout<<ans1+1<<' '<<ans2+1<<endl;
    
    return 0;
}