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
    vector<int> par;                       //親
    vector<int> rank;                      //木の深さ
    vector<P> scale;                     //木のサイズ
    int idx=0;
    unionFind(int n);
    ~unionFind();
    void push(int si, int val){
        par.push_back(idx);
        rank.push_back(0);
        scale.push_back(P(si,val));
    }
    int find(int x);                //木の根を求める
    void unite(int x,int y,int val);        //xとyの属する集合を併合
    bool same(int x,int y);         //xとyが同じ集合に属するか否か
    int size(int x);                //xの属する集合のサイズ
    int value(int x){
        x=find(x);
        return scale[x].second;
    }
};

unionFind::unionFind(int n){
    par.resize(n);
    rank.resize(n);
    scale.resize(n);
    for(int i=0;i<n;i++){
        par[i]=i;
        rank[i]=0;
        scale[i]=P(1,1);
    }
}

unionFind::~unionFind(){
}

int unionFind::find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}

void unionFind::unite(int x,int y,int val){
    x=find(x);
    y=find(y);
    scale[x].second=val;
    scale[y].second=val;
    if(x==y) return;
    if(rank[x]<rank[y]){
        par[x]=y;
        scale[y].first+=scale[x].first;
    }else{
        par[y]=x;
        scale[x].first+=scale[y].first;
        if(rank[x]==rank[y]) rank[x]++;
    }
}

bool unionFind::same(int x,int y){
    return find(x)==find(y);
}

int unionFind::size(int x){
    x=find(x);
    return scale[x].first;
}

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};

int id;
int N,K;
int S[100][100];

void solve1(){
    cout<<0<<endl;
}

void solve2(){
    vector<int> maxcnt(10,0);
    vector<vector<int>> chk(N,vector<int>(N,0));
    rep(i,N){
        rep(j,N){
            if(chk[i][j]) continue;
            int cnt=0;
            queue<P> q;
            q.push(P(i,j));
            while(!q.empty()){
                P p=q.front(); q.pop();
                cnt++;
                rep(k,4){
                    int x=p.first+I[k];
                    int y=p.second+J[k];
                    if(0<=x && x<N && 0<=y && y<N && S[x][y]==S[p.first][p.second]
                    && chk[x][y]==0){
                        chk[x][y]=1;
                        q.push(P(x,y));
                    }
                }
            }
            maxcnt[S[i][j]]=max(maxcnt[S[i][j]],cnt);
        }
    }
    repn(i,9) cout<<i<<' '<<maxcnt[i]<<endl;

    vector<P> G;
    rep(i,N) fill(chk[i].begin(),chk[i].end(),0);
    int idx=0;
    rep(i,N){
        rep(j,N){
            if(chk[i][j]) continue;
            int cnt=0;
            queue<P> q;
            q.push(P(i,j));
            while(!q.empty()){
                P p=q.front(); q.pop();
                cnt++;
                rep(k,4){
                    int x=p.first+I[k];
                    int y=p.second+J[k];
                    if(0<=x && x<N && 0<=y && y<N && S[x][y]==S[p.first][p.second]
                    && chk[x][y]==0){
                        chk[x][y]=1;
                        q.push(P(x,y));
                    }
                }
            }
            G.push_back(P(idx,cnt));
        }
    }


    unionFind uf(0);
    rep(i,N){
        rep(j,N){
            uf.push(1,S[i][j]);
        }
    }
    int idx=0;
    rep(i,N){
        rep(j,N){
            if(chk[i][j]) continue;
            int cnt=0;
            queue<P> q;
            q.push(P(i,j));
            while(!q.empty()){
                P p=q.front(); q.pop();
                cnt++;
                rep(k,4){
                    int x=p.first+I[k];
                    int y=p.second+J[k];
                    if(0<=x && x<N && 0<=y && y<N && S[x][y]==S[p.first][p.second]
                    && chk[x][y]==0){
                        chk[x][y]=1;
                        q.push(P(x,y));
                    }
                }
            }
            G.push_back(P(idx,cnt));
        }
    }
}

void input(){
    cin>>id>>N>>K;
    rep(i,N){
        string s;
        cin>>s;
        rep(j,N){
            S[i][j]=s[j]-'0';
        }
    }
}

int main(){
    input();

    //solve1();
    solve2();
}