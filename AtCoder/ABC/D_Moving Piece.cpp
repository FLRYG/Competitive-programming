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
//int const INF=1001001001;
ll const INF=1001001001001001001;
ll const MOD=1000000007;

struct unionFind{
    int* par;                       //親
    int* rank;                      //木の深さ
    int* scale;                     //木のサイズ
    int quantity;                   //木の個数
    unionFind(int n);
    ~unionFind();
    int find(int x);                //木の根を求める
    void unite(int x,int y);        //xとyの属する集合を併合
    bool same(int x,int y);         //xとyが同じ集合に属するか否か
    int size(int x);                //xの属する集合のサイズ
    int count();                    //木の個数
};

unionFind::unionFind(int n){
    par=new int[n];
    rank=new int[n];
    scale=new int[n];
    quantity=n;
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

bool unionFind::same(int x,int y){
    return find(x)==find(y);
}

int unionFind::size(int x){
    x=find(x);
    return scale[x];
}

int unionFind::count(){
    return quantity;
}

ll N,K;
ll P[5001];
ll C[5001];

int main(){
    cin>>N>>K;
    repn(i,N) cin>>P[i];
    repn(i,N) cin>>C[i];

    unionFind uf(N+1);
    repn(i,N) uf.unite(i,P[i]);

    vector<ll> point(N,0);
}

// int main(){
//     cin>>N>>K;
//     repn(i,N) cin>>P[i];
//     repn(i,N) cin>>C[i];

//     ll ans=-INF;
//     repn(idx,N){
//         ll sum=C[idx];
//         ll cnt=1;
//         for(int pos=P[idx];pos!=idx;pos=P[pos]){
//             sum+=C[pos];
//             cnt++;
//         }
        
//         ll res=0;
//         if(sum>0) res=K/cnt*sum;
//         ll roop=K%cnt;
//         if(roop==0) roop=cnt;
//         //cout<<idx<<' '<<sum<<' '<<cnt<<' '<<res<<endl;
//         for(int pos=P[idx],i=0;i<roop;pos=P[pos],i++){
//             res+=C[pos];
//             ans=max(ans,res);
//         }
//     }
//     cout<<ans<<endl;
// }

/*
ll N,K;
ll P[5001];
ll C[5001];
bool chk[5001];
ll maxi[5001];

int main(){
    cin>>N>>K;
    repn(i,N) cin>>P[i];
    repn(i,N) cin>>C[i];

    ll ans=-INF;
    repn(idx,N){
        ll res=0;
        ll pos=idx;
        ll cnt=0;
        ll sup=-INF;
        fill(chk,chk+N+1,false);
        repn(i,K){
            pos=P[pos];
            //cout<<idx<<' '<<pos<<endl;
            if(chk[pos]){
                ll m=K/cnt;
                if(res>0){
                    res=m*res+maxi[K%cnt];
                    //cout<<res<<endl;
                    ans=max(ans,res);
                }
                break;
            }
            cnt++;
            chk[pos]=true;
            res+=C[pos];
            if(res>sup) sup=res;
            maxi[cnt]=sup;
            //cout<<res<<endl;
            ans=max(ans,res);
        }
    }
    cout<<ans<<endl;
}
*/