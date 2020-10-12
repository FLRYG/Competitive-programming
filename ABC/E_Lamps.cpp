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
ll const MOD=1000000007;

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

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

ll H,W;
string S[2000];

int main(){
    cin>>H>>W;
    rep(i,H) cin>>S[i];

    ll K=0;
    rep(i,H) rep(j,W) if(S[i][j]=='.') K++;

    unionFind R(H*W);
    unionFind C(H*W);
    rep(i,H) rep(j,W-1) if(S[i][j]=='.' && S[i][j+1]=='.') R.unite(W*i+j,W*i+(j+1));
    rep(i,H-1) rep(j,W) if(S[i][j]=='.' && S[i+1][j]=='.') C.unite(W*i+j,W*(i+1)+j);

    ll ans=0;
    ll K2=mpow(2,K);
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='#') continue;
            //cout<<"R "<<R.size(W*i+j)<<endl;
            //cout<<"C "<<C.size(W*i+j)<<endl;
            ll cnt=R.size(W*i+j)+C.size(W*i+j)-1;
            ans+=K2-mpow(2,K-cnt);
            ans%=MOD;
        }
    }
    ans=(ans+MOD)%MOD;

    cout<<ans<<endl;
}