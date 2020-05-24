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
typedef pair<int,int> Pa;

int const veci[4]={0,-1,0,1};
int const vecj[4]={-1,0,1,0};
int N;
int P[250000];
int G[500][500];
int S[500][500];

int main(){
    cin>>N;
    rep(i,N*N) cin>>P[i];
    rep(i,N){
        rep(j,N){
            G[i][j]=min(min(i,j),min(N-i-1,N-j-1));
        }
    }
    rep(i,N) fill(S[i],S[i]+N,1);
    //rep(i,N){rep(j,N){cout<<G[i][j];}cout<<endl;}cout<<endl;

    int ans=0;
    rep(i,N*N){
        int i1=(P[i]-1)/N;
        int j1=(P[i]-1)%N;
        ans+=G[i1][j1];
        //cout<<"P="<<P[i]<<" ans="<<ans<<endl;
        S[i1][j1]=0;

        queue<Pa> que;
        que.push(Pa(i1,j1));
        while(!que.empty()){
            Pa p=que.front(); que.pop();
            //cout<<"i="<<p.first<<", j="<<p.second<<endl;
            rep(k,4){
                int i2=p.first+veci[k];
                int j2=p.second+vecj[k];
                if(0<=i2 && i2<N && 0<=j2 && j2<N){
                    if(S[p.first][p.second]==0 && G[p.first][p.second]<G[i2][j2]){
                        G[i2][j2]=G[p.first][p.second];
                        que.push(Pa(i2,j2));
                    }
                    if(S[p.first][p.second]==1 && G[p.first][p.second]+1<G[i2][j2]){
                        G[i2][j2]=G[p.first][p.second]+1;
                        que.push(Pa(i2,j2));
                    }
                }
            }     
        }
        //rep(x,N){rep(y,N){cout<<G[x][y];}cout<<endl;}cout<<endl;
        //rep(x,N){rep(y,N){cout<<S[x][y];}cout<<endl;}cout<<'\n'<<endl;
    }

    cout<<ans<<endl;
}

/* ダメ
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

int const vec1[4]={0,-1,0,1};
int const vec2[4]={1,0,-1,0};
int N;
int P[500];
int G[500][500];

int main(){
    cin>>N;
    rep(i,N*N){
        cin>>P[i];
        P[i]--;
    }
    unionFind uf(N*N+1);
    rep(i,N+2){
        uf.unite(0,i);
        uf.unite(0,i*N);
        uf.unite(0,N*N-i+1);
        uf.unite(0,1+(i-1)*N);
    }
    rep(i,N) fill(G[i],G[i]+N,1);

    int ans=0;
    rep(n,N*N){
        int i=P[n]/N;
        int j=P[n]%N;
        G[i][j]=0;
        rep(i,N){
            rep(j,N){
                cout<<G[i][j];
            }
            cout<<endl;
        }
        //cout<<P[n]+1<<endl;
        for(int k=0;k<4;k++){
            int i1=i+vec1[k];
            int j1=j+vec2[k];
            //cout<<i1<<' '<<j1<<endl;
            if(i1==-1 || i1==N || j1==-1 || j1==N){
                uf.unite(0,P[n]+1);
                //cout<<"unite "<<0<<' '<<P[n]+1<<endl;
            }else{
                int x=i1*N+j1+1;
                if(!G[i1][j1]){
                    uf.unite(P[n]+1,x);
                    //cout<<"unite "<<P[n]+1<<' '<<x<<endl;
                }
            }
        }
        if(!uf.same(P[n]+1,0)){
            queue<pair<PA,int>> q;
            q.push(pair<PA,int>(PA(i,j),0));
            int g[500][500];
            while(!q.empty()){
                pair<PA,int> pa=q.front();q.pop();
                int i1=pa.first.first;
                int j1=pa.first.second;
                int point=pa.second;
                for(int k=0;k<4;k++){
                    int i2=i1+vec1[k];
                    int j2=j1+vec2[k];
                    if(G[i2][j2]==1){
                        point++;
                    }
                    queue()
                }
            }
            ans++;
            //cout<<"ans:"<<ans<<endl;
        }
        //cout<<endl;
    }

    cout<<ans<<endl;
}
*/