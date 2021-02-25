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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

struct unionFind{
    int n;
    vector<int> par;                       //親
    vector<int> rank;                      //木の深さ
    vector<int> scale;                     //木のサイズ
    vector<map<int,int>> m;
    int quantity;                          //木の個数
    unionFind(int _n, vector<int> &C): n(_n){
        par.resize(n);
        rank.resize(n);
        scale.resize(n);
        m.resize(n);
        quantity=n;
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
            scale[i]=1;
            m[i][C[i]]++;
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
            for(auto e:m[x]) m[y][e.first]+=e.second;
        }else{
            par[y]=x;
            scale[x]+=scale[y];
            for(auto e:m[y]) m[x][e.first]+=e.second;
            if(rank[x]==rank[y]) rank[x]++;
        }
    }
    //xとyが同じ集合に属するか否か
    bool same(int x,int y){ return find(x)==find(y); }
    //xの属する集合のサイズ
    int size(int x){ return scale[find(x)]; }
    //木の個数
    int count(){ return quantity; }

    int query(int x, int y){
        return m[find(x)][y];
    }
};

int N,Q;

int main(){
    cin>>N>>Q;
    vector<int> C(N);
    rep(i,N){
        cin>>C[i];
        C[i]--;
    }

    unionFind uf(N,C);
    vector<int> ans;
    rep(q,Q){
        int k,a,b;
        cin>>k>>a>>b;
        a--, b--;
        if(k==1){
            uf.unite(a,b);
        }else{
            ans.push_back(uf.query(a,b));
        }
    }

    repr(e,ans) cout<<e<<endl;
    
    return 0;
}