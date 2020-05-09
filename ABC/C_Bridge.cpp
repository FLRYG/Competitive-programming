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
    delete[] par,rank,scale;
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

int N,M;
int a[2500],b[2500];

int main(){
    cin>>N>>M;
    rep(i,M) cin>>a[i]>>b[i];

    int ans=0;
    rep(i,M){
        unionFind uf(N+1);
        rep(j,M){
            if(i==j) continue;
            uf.unite(a[j],b[j]);
        }
        repn(j,N-1){
            if(!uf.same(j,j+1)){
                ans++;
                break;
            }
        }
    }

    cout<<ans<<endl;
}