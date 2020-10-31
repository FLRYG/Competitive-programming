#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
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
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=998244353;

struct unionFind{
    int* par;                       //親
    int* rank;                      //木の深さ
    int* scale;                     //木のサイズ
    unionFind(int n);
    ~unionFind();
    int find(int x);                //木の根を求める
    void unite(int x,int y);        //xとyの属する集合を併合
    bool same(int x,int y);         //xとyが同じ集合に属するか否か
    int size(int x);                //xの属する集合のサイズ
};

unionFind::unionFind(int n){
    par=new int[n];
    rank=new int[n];
    scale=new int[n];
    for(int i=0;i<n;i++){
        par[i]=i;
        rank[i]=0;
        scale[i]=1;
    }
}

unionFind::~unionFind(){
    delete[] par;
    delete[] rank;
    delete[] scale;
}

int unionFind::find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}

void unionFind::unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(rank[x]<rank[y]){
        par[x]=y;
        scale[y]+=scale[x];
    }else{
        par[y]=x;
        scale[x]+=scale[y];
        if(rank[x]==rank[y]) rank[x]++;
    }
}

bool unionFind::same(int x,int y){
    return find(x)==find(y);
}

int unionFind::size(int x){
    x=find(x);
    return scale[x];
}

ll mfrac(ll n){
    if(n==0) return 1;
    else return n*mfrac(n-1)%MOD;
}

ll N,K;
ll a[50][50];

int main(){
    cin>>N>>K;
    rep(i,N) rep(j,N) cin>>a[i][j];

    unionFind ufr(N);
    unionFind ufc(N);
    rep(x,N-1){
        for(int y=x+1;y<N;y++){
            bool c=true, r=true;
            rep(i,N){
                c&=a[i][x]+a[i][y]<=K;
                r&=a[x][i]+a[y][i]<=K;
            }
            if(c) ufc.unite(x,y);
            if(r) ufc.unite(x,y);
        }
    }

    vector<bool> chkr(N,true);
    vector<bool> chkc(N,true);
    ll cntr=1;
    ll cntc=1;
    rep(i,N){
        if(chkr[ufr.find(i)]){
            cntr*=mfrac(ufr.size(i));
            cntr%=MOD;
            chkr[ufr.find(i)]=false;
        }
        if(chkc[ufc.find(i)]){
            cntc*=mfrac(ufc.size(i));
            cntc%=MOD;
            chkc[ufc.find(i)]=false;
        }
    }
    cout<<cntr<<' '<<cntc<<endl;

    ll ans=cntr*cntc%MOD;
    cout<<ans<<endl;
}