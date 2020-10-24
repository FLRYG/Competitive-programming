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
//typedef pair<int,int> P;
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

int N;
string s,t;

int main(){
    cin>>N>>s>>t;

    unionFind uf(100);
    rep(i,N){
        if('A'<=s[i] && s[i]<='Z' && 'A'<=t[i] && t[i]<='Z'){
            uf.unite(s[i],t[i]);
        }
    }

    vector<bool> chk(100,false);
    rep(i,26) chk[i+'A']=true;
    rep(i,N){
        if('0'<=s[i] && s[i]<='9' && 'A'<=t[i] && t[i]<='Z'){
            chk[uf.find(t[i])]=false;
        }if('A'<=s[i] && s[i]<='Z' && '0'<=t[i] && t[i]<='9'){
            chk[uf.find(s[i])]=false;
        }
    }

    ll ans=1;
    if(chk[uf.find(s[0])]){
        ans*=9;
        chk[uf.find(s[0])]=false;
    }
    repn(i,N-1){
        if(chk[uf.find(s[i])]){
            ans*=10;
            chk[uf.find(s[i])]=false;
        }
    }

    cout<<ans<<endl;
}

/*
int main(){
    cin>>N>>s>>t;

    bool flag=true;
    while(flag){
        flag=false;
        rep(i,N){
            if('0'<=s[i] && s[i]<='9' && 'A'<=t[i] && t[i]<='Z'){
                // cout<<"aaaaa"<<endl;
                flag=true;
                char c=t[i];
                char n=s[i];
                rep(j,N) if(s[j]==c) s[j]=n;
                rep(j,N) if(t[j]==c) t[j]=n;
            }
            if('A'<=s[i] && s[i]<='Z' && '0'<=t[i] && t[i]<='9'){
                // cout<<"bbbbb"<<endl;
                flag=true;
                char c=s[i];
                char n=t[i];
                rep(j,N) if(s[j]==c) s[j]=n;
                rep(j,N) if(t[j]==c) t[j]=n;
            }
        }
    }
    rep(i,26){
        char c='A'+i;
        rep(i,N){
            if(s[i]==c || t[i]==c){
                s[i]=c;
                t[i]=c;
            }
        }
    }
    // cout<<s<<endl;
    // cout<<t<<endl;

    vector<int> cnt(26);
    repn(i,N-1){
        if('A'<=s[i] && s[i]<='Z') cnt[s[i]-'A']=1;
    }
    if('A'<=s[0] && s[0]<='Z') cnt[s[0]-'A']=2;

    ll ans=1;
    rep(i,26){
        if(cnt[i]==1) ans*=10;
        if(cnt[i]==2) ans*=9;
    }

    cout<<ans<<endl;
}
*/