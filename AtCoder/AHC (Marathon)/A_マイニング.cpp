#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
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
    int* par;                       //親
    int* rank;                      //木の深さ
    int* scale;                     //木のサイズ
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

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};

int H=50;
int W=50;
int C;
int p[50][50];

void input(){
    cin>>C;
    rep(i,H) rep(j,W) cin>>p[i][j];
}

// 全部削るだけ
vector<P> solve01(){
    vector<P> ans;
    rep(i,H){
        rep(j,W){
            ans.push_back(P(i,j));
        }
    }
    return ans;
}

pair<ll,vector<P>> bfs02(int xs, int ys, vector<vector<int>> &ok, vector<vector<bool>> &chk){
    ll cost=0;
    vector<P> res;
    queue<P> q;
    q.push(P(xs,ys));
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        //cout<<i<<' '<<j<<endl;
        q.pop();
        if(!chk[i][j]) continue;
        res.push_back(P(i,j));
        chk[i][j]=false;
        int cnt=0;
        rep(k,4){
            int x=i+I[k];
            int y=j+J[k];
            if(!chk[x][y]) cnt++;
            else if(ok[x][y]==2){
                q.push(P(x,y));
            }
        }
        cost+=p[i][j]-C/cnt;
    }
    return pair<ll,vector<P>>(cost,res);
}

vector<P> solve02(){
    vector<P> ans;
    vector<vector<int>> ok(H,vector<int>(W,0));
    rep(i,H){
        rep(j,W){
            if(p[i][j]-C/4>=0) ok[i][j]=1;
        }
    }
    unionFind uf(H*W);
    rep(i,H){
        if(i==0 || i==H-1) continue;
        rep(j,W){
            if(j==0 || j==W-1) continue;
            if(ok[i][j]){
                if(ok[i-1][j]) uf.unite(i*H+j,(i-1)*H+j);
                if(ok[i][j-1]) uf.unite(i*H+j,i*H+(j-1));
            }
        }
    }
    int maxi=0;
    int idx=0;
    rep(i,H*W){
        if(maxi<uf.size(i)){
            maxi=uf.size(i);
            idx=i;
        }
    }
    rep(i,H){
        rep(j,W){
            if(uf.same(idx,i*H+j)) ok[i][j]=2;
        }
    }
    // rep(i,H){rep(j,W){cout<<ok[i][j];}cout<<endl;}
    // cout<<"size="<<maxi<<endl;

    vector<int> twoh(H,0);
    vector<int> twov(W,0);
    rep(i,H){
        rep(j,W){
            if(ok[i][j]==2){
                twoh[i]=1;
                twov[j]=1;
            }
        }
    }

    ll bnf=0;
    rep(i,H){
        if(!twoh[i]) continue;
        ll mon=0;
        vector<P> vec;
        vector<vector<bool>> chk(H,vector<bool>(W,true));
        rep(j,W){
            if(j==0){
                vec.push_back(P(i,j));
                chk[i][j]=false;
                mon+=p[i][j]-C/3;
            }else if(ok[i][j]==2){
                pair<ll,vector<P>> res=bfs02(i,j,ok,chk);
                mon=res.first;
                vector<P> tmp=res.second;
                repr(e,tmp) vec.push_back(e);
                break;
            }else{
                vec.push_back(P(i,j));
                chk[i][j]=false;
                mon+=p[i][j]-C;
            }
        }
        cout<<i<<' '<<mon<<endl;
        if(bnf<mon){
            bnf=mon;
            ans=vec;
        }
    }

    return ans;
}

int main(){
    input();

    // vector<vector<int>> ok(H,vector<int>(W));
    // rep(i,H){
    //     rep(j,W){
    //         if(p[i][j]-C/4>=0) ok[i][j]=4;
    //         if(p[i][j]-C/3>=0) ok[i][j]=3;
    //         if(p[i][j]-C/2>=0) ok[i][j]=2;
    //         if(p[i][j]-C/1>=0) ok[i][j]=1;
    //     }
    // }
    // rep(i,H){rep(j,W){cout<<ok[i][j];}cout<<endl;}
    // rep(i,H){rep(j,W){cout<<(ok[i][j]?'o':'.');}cout<<endl;}

    // ll bnf=0;
    // rep(i,H){
    //     rep(j,W) bnf+=p[i][j]; 
    // }
    // bnf-=(H-1)*(W-1)*C/2;
    // bnf-=(H-1)*C/3;
    // bnf-=(W-1)*C/3;
    // bnf-=C/4;
    // cout<<bnf<<endl;

    vector<P> ans;
    ans=solve01();
    //ans=solve02();

    int M=ans.size();
    cout<<M<<endl;
    rep(i,M) cout<<ans[i].first<<' '<<ans[i].second<<endl;
    
    return 0;
}