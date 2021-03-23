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
    vector<int> wt;
    vector<int> val;
    int quantity;                          //木の個数
    unionFind(int _n): n(_n){
        par.resize(n);
        rank.resize(n);
        scale.resize(n);
        wt.resize(n);
        val.resize(n);
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
            wt[y]+=wt[x];
            val[y]+=val[x];
        }else{
            par[y]=x;
            scale[x]+=scale[y];
            wt[x]+=wt[y];
            val[x]+=val[y];
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

int N,M,W;

int main(){
    cin>>N>>M>>W;
    unionFind uf(N);
    rep(i,N) cin>>uf.wt[i]>>uf.val[i];
    rep(i,M){
        int a,b;
        cin>>a>>b;
        uf.unite(a-1,b-1);
    }
    vector<int> chk(N,true);
    vector<int> w(0), v(0);
    rep(i,N){
        int x=uf.find(i);
        if(chk[x]){
            w.push_back(uf.wt[x]);
            v.push_back(uf.val[x]);
            chk[x]=false;
        }
    }
    N=w.size();
    // rep(i,N) cout<<w[i]<<' '<<v[i]<<endl;

    vector<vector<int>> dp(N+1,vector<int>(W+1,0));
    repn(i,N){
        repn(j,W){
            dp[i][j]=dp[i-1][j];
            if(w[i-1]<=j) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i-1]]+v[i-1]);
        }
    }

    int ans=0;
    repn(j,W) ans=max(ans,dp[N][j]);

    cout<<ans<<endl;
    
    return 0;
}