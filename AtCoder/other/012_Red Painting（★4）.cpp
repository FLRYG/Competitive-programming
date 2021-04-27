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
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
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

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};
int H,W,Q;

int main(){
    cin>>H>>W>>Q;

    unionFind uf(H*W);
    vector<int> col(H*W,0);
    while(Q--){
        int t;
        cin>>t;
        if(t==1){
            int r,c;
            cin>>r>>c;
            r--, c--;
            int x=W*r+c;
            col[x]=1;
            rep(k,4){
                int i=r+I[k];
                int j=c+J[k];
                int y=W*i+j;
                if(0<=i && i<H && 0<=j && j<W && col[y]){
                    uf.unite(x,y);
                }
            }
        }else{
            int ra,ca,rb,cb;
            cin>>ra>>ca>>rb>>cb;
            ra--, ca--, rb--, cb--;
            int x=W*ra+ca;
            int y=W*rb+cb;
            string ans="No";
            if(uf.same(x,y) && col[x] && col[y]) ans="Yes";
            cout<<ans<<endl;
        }
    }
    
    return 0;
}