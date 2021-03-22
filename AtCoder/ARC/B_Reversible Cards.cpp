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
typedef pair<int,int> P;
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

int N;

int main(){
    cin>>N;
    unionFind uf(400000);
    vector<int> tree(400000,true);
    rep(i,N){
        int a,b;
        cin>>a>>b;
        a--, b--;
        if(uf.find(a)==uf.find(b)) tree[uf.find(a)]=false;
        else{
            int f=tree[uf.find(a)]&tree[uf.find(b)];
            uf.unite(a,b);
            tree[uf.find(a)]=f;
        }
    }

    int ans=0;
    vector<int> chk(400000,true);
    rep(i,400000){
        int r=uf.find(i);
        if(chk[r]){
            ans+=uf.size(r);
            if(tree[r]) ans--;
            chk[r]=false;
        }
    }

    cout<<ans<<endl;

    return 0;
}

// int N;
// int a[200000];
// int b[200000];

// int main(){
//     cin>>N;
//     rep(i,N) cin>>a[i]>>b[i];

//     vector<int> cnt(400001,0);
//     rep(i,N){
//         cnt[a[i]]++;
//         cnt[b[i]]++;
//     }

//     int ans=0;
//     rep(i,N){
//         if(cnt[a[i]]==1 || cnt[b[i]]==1){
//             ans++;
//             cnt[a[i]]--;
//             cnt[b[i]]--;
//         }else if(a[i]==b[i] && cnt[a[i]]){
//             ans++;
//             cnt[a[i]]=0;
//         }
//     }
//     repr(e,cnt) if(e) ans++;

//     // rep(i,N){
//     //     if(a[i]>b[i]) swap(a[i],b[i]);
//     // }

//     // vector<P> v(N);
//     // rep(i,N) v[i]=P(a[i],b[i]);

//     // sort(v.begin(),v.end());

//     // int ans=0;
//     // vector<int> cnt(400001,0);
//     // rep(i,N) cnt[v[i].second]++;
//     // repr(e,cnt) if(e) ans++;
//     // rep(i,N){
//     //     if(cnt[v[i].first]==0 && cnt[v[i].second]>1){
//     //         ans++;
//     //         cnt[v[i].first]++;
//     //         cnt[v[i].second]--;
//     //     }
//     // }

//     // rep(i,N){
//     //     if(cnt[v[i].first]==0){
//     //         ans++;
//     //         cnt[v[i].first]++;
//     //     }else if(cnt[v[i].second]==0){
//     //         ans++;
//     //         cnt[v[i].second]++;
//     //     }
//     // }

//     // int ans=0;
//     // vector<int> cnt(400001,0);
//     // rep(i,N) cnt[a[i]]++;
//     // repr(e,cnt) if(e) ans++;

//     // rep(i,N){
//     //     if(cnt[b[i]]==0 && cnt[a[i]]>1){
//     //         ans++;
//     //         cnt[b[i]]++;
//     //         cnt[a[i]]--;
//     //     }
//     // }

//     cout<<ans<<endl;
    
//     return 0;
// }