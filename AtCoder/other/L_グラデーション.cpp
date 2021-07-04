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
typedef pair<int,int> P;
typedef pair<double,P> DP;
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

int N,M;
int x[30], y[30], c[30];
int X[30], Y[30], C[30];

double dist(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int main(){
    cin>>N>>M;
    rep(i,N) cin>>x[i]>>y[i]>>c[i];
    rep(i,M) cin>>X[i]>>Y[i]>>C[i];

    vector<DP> costH;
    rep(i,N-1) for(int j=i+1;j<N;j++){
        double d=dist(x[i],y[i],x[j],y[j]);
        if(c[i]!=c[j]) d*=10;
        costH.push_back(DP(d,{i,j}));
    }

    double ans=INF;
    rep(i,1<<M){
        vector<DP> cost=costH;
        vector<int> Lid;
        rep(j,M) if(i>>j&1){
            rep(k,N){
                double d=dist(X[j],Y[j],x[k],y[k]);
                if(C[j]!=c[k]) d*=10;
                cost.push_back(DP{d,{N+Lid.size(),k}});
            }
            Lid.push_back(j);
        }
        if(Lid.size()) rep(j,Lid.size()-1) for(int k=j+1;k<Lid.size();k++){
            double d=dist(X[Lid[j]],Y[Lid[j]],X[Lid[k]],Y[Lid[k]]);
            if(C[Lid[j]]!=C[Lid[k]]) d*=10;
            cost.push_back(DP{d,{N+j,N+k}});
        }
        sort(cost.begin(),cost.end());
        unionFind uf(N+Lid.size());
        double res=0;
        repr(e,cost){
            if(!uf.same(e.second.first,e.second.second)){
                uf.unite(e.second.first,e.second.second);
                res+=e.first;
            }
            if(uf.size(0)==N+Lid.size()) break;
        }
        ans=min(ans,res);
    }

    cout<<setprecision(16)<<ans<<endl;
    
    return 0;
}