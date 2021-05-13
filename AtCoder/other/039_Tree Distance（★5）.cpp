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

int N;

void f(int v, int p, int k, vector<ll> &d, vector<vector<int>> &G){
    d[v]=k;
    repr(e,G[v]) if(e!=p){
        f(e,v,k+1,d,G);
    }
}

ll g(int v, int p, vector<ll> &cnt, vector<vector<int>> &G){
    ll res=1;
    repr(e,G[v]) if(e!=p){
        res+=g(e,v,cnt,G);
    }
    return cnt[v]=res;
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

    vector<ll> d(N), cnt(N);
    f(0,-1,0,d,G);
    g(0,-1,cnt,G);

    ll ans=0;
    rep(i,N) repr(j,G[i]){
        if(d[i]>d[j]) ans+=cnt[i]*(N-cnt[i]);
        else ans+=cnt[j]*(N-cnt[j]);
    }
    ans/=2;

    cout<<ans<<endl;
    
    return 0;
}