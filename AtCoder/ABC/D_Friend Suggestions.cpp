#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

struct unionFind{
    int* par;                       //親
    int* rank;                      //木の深さ
    int* scale;
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

int N,M,K;
vector<int> fri[100000];
vector<int> blo[100000];

int main(){
    cin>>N>>M>>K;
    unionFind uf(N);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        fri[a-1].push_back(b-1);
        fri[b-1].push_back(a-1);
        uf.unite(a-1,b-1);
    }
    rep(i,K){
        int c,d;
        cin>>c>>d;
        blo[c-1].push_back(d-1);
        blo[d-1].push_back(c-1);
    }

    rep(i,N){
        int ans=uf.size(i)-fri[i].size()-1;
        rep(j,blo[i].size()){
            if(uf.same(i,blo[i][j])) ans--;
        }
        cout<<ans<<' ';
    }

    cout<<endl;
}