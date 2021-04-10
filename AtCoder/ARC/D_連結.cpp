#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
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

int N,K,L;

int main(){
    cin>>N>>K>>L;
    unionFind a(N), b(N);
    int p,q;
    rep(i,K){
        cin>>p>>q;
        p--, q--;
        a.unite(p,q);
    }
    rep(i,L){
        cin>>p>>q;
        p--, q--;
        if(a.same(p,q)) b.unite(p,q);
    }

    rep(i,N){
        cout<<b.size(i)<<' ';
    }
    cout<<endl;
    
    return 0;
}



// struct unionFind{
//     int* par;                       //親
//     int* rank;                      //木の深さ
//     int* scale;                     //木のサイズ
//     int quantity;                   //木の個数
//     unionFind(int n);
//     ~unionFind();
//     int find(int x);                //木の根を求める
//     void unite(int x,int y);        //xとyの属する集合を併合
//     bool same(int x,int y);         //xとyが同じ集合に属するか否か
//     int size(int x);                //xの属する集合のサイズ
//     int count();                    //木の個数
// };

// unionFind::unionFind(int n){
//     par=new int[n];
//     rank=new int[n];
//     scale=new int[n];
//     quantity=n;
//     for(int i=0;i<n;i++){
//         par[i]=i;
//         rank[i]=0;
//         scale[i]=1;
//     }
// }

// unionFind::~unionFind(){
//     delete[] par;
//     delete[] rank;
//     delete[] scale;
// }

// int unionFind::find(int x){
//     if(par[x]==x) return x;
//     return par[x]=find(par[x]);
// }

// void unionFind::unite(int x,int y){
//     x=find(x);
//     y=find(y);
//     if(x==y) return;
//     quantity--;
//     if(rank[x]<rank[y]){
//         par[x]=y;
//         scale[y]+=scale[x];
//     }else{
//         par[y]=x;
//         scale[x]+=scale[y];
//         if(rank[x]==rank[y]) rank[x]++;
//     }
// }

// bool unionFind::same(int x,int y){
//     return find(x)==find(y);
// }

// int unionFind::size(int x){
//     x=find(x);
//     return scale[x];
// }

// int unionFind::count(){
//     return quantity;
// }

// int N,K,L;
// int p[100000];
// int q[100000];
// int r[100000];
// int s[100000];

// int main(){
//     cin>>N>>K>>L;
//     unionFind uf1(N+1), uf2(N+1), uf3(N+1), uf4(N+1);
//     rep(i,K) cin>>p[i]>>q[i];
//     rep(i,L) cin>>r[i]>>s[i];

//     rep(i,K) uf1.unite(p[i],q[i]);
//     rep(i,L) if(uf1.same(r[i],s[i])) uf3.unite(r[i],s[i]);
//     rep(i,L) uf2.unite(r[i],s[i]);
//     rep(i,K) if(uf2.same(p[i],q[i])) uf4.unite(p[i],q[i]);

//     repn(i,N){
//         cout<<max(uf3.size(i),uf4.size(i))<<' ';
//     }
//     cout<<endl;
    
//     return 0;
// }