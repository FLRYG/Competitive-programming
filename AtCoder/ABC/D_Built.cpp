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
typedef pair<ll,ll> P;
typedef pair<ll,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

struct unionFind{
    int n;
    vector<int> par;                       //親
    vector<int> rank;                      //木の深さ
    vector<int> scale;                     //木のサイズ
    int quantity;                          //木の個数
    unionFind(int _n): n(_n){
        par.resize(n);
        rank.resize(n);
        scale.resize(n);
        quantity=n;
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
            scale[i]=1;
        }
    };
    ~unionFind(){}
    //木の根を求める
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    //xとyの属する集合を併合
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y) return;
        quantity--;
        if(rank[x]<rank[y]){
            par[x]=y;
            scale[y]+=scale[x];
        }else{
            par[y]=x;
            scale[x]+=scale[y];
            if(rank[x]==rank[y]) rank[x]++;
        }
    }
    //xとyが同じ集合に属するか否か
    bool same(int x,int y){ return find(x)==find(y); }
    //xの属する集合のサイズ
    int size(int x){ return scale[find(x)]; }
    //木の個数
    int count(){ return quantity; }
};

ll N;
ll x[100000];
ll y[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>x[i]>>y[i];

    vector<IP> G(0);
    vector<int> id(N,0);
    iota(id.begin(),id.end(),0);

    sort(id.begin(),id.end(),[&](int i, int j){return x[i]<x[j];});
    rep(i,N-1) G.push_back(IP(x[id[i+1]]-x[id[i]],P(id[i],id[i+1])));

    sort(id.begin(),id.end(),[&](int i, int j){return y[i]<y[j];});
    rep(i,N-1) G.push_back(IP(y[id[i+1]]-y[id[i]],P(id[i],id[i+1])));
    
    sort(G.begin(),G.end());
    unionFind uf(N);
    ll ans=0;
    repr(e,G){
        if(uf.same(e.second.first,e.second.second)) continue;
        uf.unite(e.second.first,e.second.second);
        ans+=e.first;
    }

    cout<<ans<<endl;

    return 0;
}