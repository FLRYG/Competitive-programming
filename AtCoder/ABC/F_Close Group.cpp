#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
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
    int* par;                       //親
    int* rank;                      //木の深さ
    int* scale;                     //木のサイズ
    int quantity;                   //木の個数
    unionFind(int n);
    ~unionFind();
    int find(int x);                //木の根を求める
    void unite(int x,int y);        //xとyの属する集合を併合
    bool same(int x,int y);         //xとyが同じ集合に属するか否か
    int size(int x);                //xの属する集合のサイズ
    int count();                    //木の個数
};

unionFind::unionFind(int n){
    par=new int[n];
    rank=new int[n];
    scale=new int[n];
    quantity=n;
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

bool unionFind::same(int x,int y){
    return find(x)==find(y);
}

int unionFind::size(int x){
    x=find(x);
    return scale[x];
}

int unionFind::count(){
    return quantity;
}

int N,M;
int A[200];
int B[200];
int G[18][18];
int H[18][18];

int main(){
    cin>>N>>M;
    rep(i,M){
        cin>>A[i]>>B[i];
        A[i]--;
        B[i]--;
        G[A[i]][B[i]]=1;
        G[B[i]][A[i]]=1;
    }


    int ans=INF;
    rep(n,1<<N){
        unionFind uf(N);
        rep(i,N-1){
            for(int j=i+1;j<N;j++){
                if(n>>i&1 && n>>j&1 && G[i][j]){
                    H[i][j]=1;
                    uf.unite(i,j);
                }else{
                    H[i][j]=0;
                }
            }
        }
        rep(i,N-1){
            for(int j=i+1;j<N;j++){
                if(uf.same(i,j) && H[i][j]==0) goto a;
            }
        }
        //cout<<n<<' '<<uf.count()<<endl;
        ans=min(ans,uf.count());
        a:;
    }

    cout<<ans<<endl;
    
    return 0;
}