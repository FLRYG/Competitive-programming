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

int N,M;

ll f(int prev, int p, int &cnt, vector<ll> &col, vector<vector<int>> &G, unionFind &uf){
    ll res=0;
    vector<int> c(3,1);
    repr(e,G[p]){
        if(col[e]!=-1) c[col[e]]&=0;
    }
    if(cnt==uf.size(p)){
        rep(i,3){
            res+=c[i];
            // if(c[i]){
            //     col[p]=i;
            //     repr(e,col) cout<<e<<' '; cout<<endl;
            //     col[p]=-1;
            // }
        }
        return res;
    }
    rep(i,3){
        if(c[i]){
            col[p]=i;
            cnt++;
            repr(e,G[p]){
                if(col[e]!=-1) continue;
                res+=f(p,e,cnt,col,G,uf);
            }
            cnt--;
            col[p]=-1;
        }
    }
    return res;
}

ll g(int prev, int p, int &cnt, vector<vector<int>> &G, unionFind &uf){
    if(uf.size(p)==cnt) return 1;
    ll res=0;
    cnt++;
    repr(e,G[p]){
        if(prev==e) continue;
        res+=g(p,e,cnt,G,uf); 
    }
    cnt--;
    return res;
}

int main(){
    cin>>N>>M;
    vector<vector<int>> G(N,vector<int>());
    unionFind uf(N);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
        uf.unite(a,b);
    }

    vector<ll> chk(N,0);
    vector<ll> col(N,-1);
    ll ans=1;
    int cnt=1;
    rep(i,N) if(!chk[uf.find(i)]){
        ans*=f(-1,i,cnt,col,G,uf)/g(-1,i,cnt,G,uf);
        chk[uf.find(i)]=1;
    }

    cout<<ans<<endl;
    
    return 0;
}