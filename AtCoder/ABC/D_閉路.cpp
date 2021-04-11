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
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

template<class T, T (*op)(T ,T), T (*e)()> struct segmentTree{
    int n;
    std::vector<T> v;
    segmentTree() : segmentTree(0){}
    segmentTree(int _n){
        n=1;
        while(n<_n) n*=2;
        v=std::vector<T>(2*n-1,e());
    }
    ~segmentTree(){}
    void set(int k, T a){
        k+=n-1;
        v[k]=a;
        while(k>0){
            k=(k-1)/2;
            v[k]=op(v[k*2+1],v[k*2+2]);
        }
    }
    T get(int k){return v[k+n-1];}
    const T& operator[](std::size_t n) const& { return v[n]; }
    T& operator[](std::size_t n) & { return v[n]; }
    T sum(int l, int r){return sum(l,r,0,0,n);}     // [l,r) 半開区間に注意
    T sum(int l, int r, int k, int a, int b){
        if(b<=l || r<=a) return e();
        if(l<=a && b<=r) return v[k];
        T vl=sum(l,r,k*2+1,a,(a+b)/2);
        T vr=sum(l,r,k*2+2,(a+b)/2,b);
        return op(vl,vr);
    }
};
P op(P a, P b){
    if(a.first<b.first) return a;
    else return b;
}
P e(){ return {INF,0}; }

int N;
vector<vector<int>> G;
vector<int> vs;
vector<int> depth;
vector<int> id;

void dfs(int x, int d, int &k, int prev){
    id[x]=k;
    vs[k]=x;
    depth[k++]=d;
    repr(e,G[x]){
        if(e==prev) continue;
        dfs(e,d+1,k,x);
        vs[k]=x;
        depth[k++]=d;
    }
}

int main(){
    cin>>N;
    G.resize(N,vector<int>());
    rep(i,N-1){
        int x,y;
        cin>>x>>y;
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vs.resize(2*N-1,-1);
    depth.resize(2*N-1,-1);
    id.resize(N,-1);
    int k=0;
    dfs(0,0,k,-1);
    
    segmentTree<P,op,e> st(2*N-1);

    
    return 0;
}