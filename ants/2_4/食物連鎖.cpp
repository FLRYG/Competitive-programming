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

class Union_Find{
private:
    int* par;                       //親
    int* rank;                      //木の深さ
public:
    Union_Find(int size);
    ~Union_Find();
    int find(int x);                //木の根を求める
    void unite(int x,int y);        //xとyの属する集合を併合
    bool same(int x,int y);         //xとyが同じ集合に属するか否か
};

Union_Find::Union_Find(int size){
    par=new int[size];
    rank=new int[size];
    for(int i=0;i<size;i++){
        par[i]=i;
        rank[i]=0;
    }
}

Union_Find::~Union_Find(){
    delete[] par;
    delete[] rank;
}

int Union_Find::find(int x){
    if(par[x]==x) return x;
    return par[x]=this->find[par[x]];
}

void Union_Find::unite(int x,int y){
    x=find(x);
    y=find(y);
    
    if(x==y) return;

    if(rank[x]<rank[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
}

bool Union_Find::same(int x,int y){
    return find(x)==find(y);
}



int N,K;
int T[100000],X[100000],Y[100000];

int main(){
    cin>>N>>K;
    rep(i,K) cin>>T[i]>>X[i]>>Y[i];

    Union_Find uf(N*3);
    int ans=0;
    for(int i=0;i<K;i++){
        int t=T[i];
        int x=X[i]-1;
        int y=Y[i]-1;

        if(x<0 || N<=x || y<0 || N<=y){
            ans++;
            continue;
        }

        if(t==1){
            if(uf.same(x,y+N) || uf.same(x,y+N*2)){
                ans++;
            }else{
                uf.unite(x,y);
                uf.unite(x+N,y+N);
                uf.unite(x+N*2,y+N*2)
            }
        }
    }
}