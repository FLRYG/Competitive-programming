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

int N,W;
int A[100];
int K[100];

int main(){
    cin>>N>>W;
    rep(i,N) cin>>A[i];
    vector<vector<int>> G(N,vector<int>());
    rep(i,N){
        cin>>K[i];
        rep(j,K[i]){
            int c;
            cin>>c;
            c--;
            G[c].push_back(i);
        }
    }

    int ans=0;
    unionFind uf(N);
    repn(n,N){
        repr(e,G[n-1]) uf.unite(n-1,e);
        vector<int> val(n,0);
        rep(i,n){
            repr(e,G[i]) val[i]+=val[e];
            val[i]+=A[i]-W;
        }

        vector<int> maxi(n,0);
        rep(i,n){
            int j=uf.find(i);
            maxi[j]=max(maxi[j],val[i]);
        }

        int res=0;
        rep(i,n) res+=maxi[i];

        ans=max(ans,res);
    }

    cout<<ans<<endl;

    return 0;
}