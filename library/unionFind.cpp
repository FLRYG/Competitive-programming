#include <iostream>
#include <vector>
using namespace std;

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