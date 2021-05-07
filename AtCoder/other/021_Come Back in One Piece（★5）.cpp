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

struct SCC{
    int N_origin;
    vector<int> G_origin;
    vector<int> G_origin_inv;
    int N;
    vector<int> G;
    SCC(vector<vector<int>> _G): N_origin(_G.size()){

    }
};

int N,M;

void f(int v, int &k, vector<int> &id ,vector<vector<int>> &G){
    id[v]=-1;
    repr(e,G[v]){
        if(id[e]==-2) f(e,k,id,G);
    }
    id[v]=k++;
}

ll g(int v, vector<int> &chk, vector<vector<int>> &G_rev){
    ll res=1;
    chk[v]=0;
    repr(e,G_rev[v]){
        if(chk[e]) res+=g(e,chk,G_rev);
    }
    return res;
}

int main(){
    cin>>N>>M;
    vector<vector<int>> G(N,vector<int>(0));
    vector<vector<int>> G_rev(N,vector<int>(0));
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--, b--;
        G[a].push_back(b);
        G_rev[b].push_back(a);
    }
    
    int k=0;
    vector<int> id(N,-2);
    rep(i,N) if(id[i]==-2) f(i,k,id,G);

    vector<int> id_inv(N);
    rep(i,N) id_inv[id[i]]=i;

    vector<int> chk(N,1);
    ll ans=0;
    for(int i=N-1;i>=0;i--){
        if(chk[id_inv[i]]){
            ll x=g(id_inv[i],chk,G_rev);
            ans+=x*(x-1)/2;
        }
    }

    cout<<ans<<endl;

    return 0;
}