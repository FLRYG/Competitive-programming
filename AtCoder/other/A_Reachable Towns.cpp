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

int N;
pair<P,int> xy[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>xy[i].first.first>>xy[i].first.second;
    rep(i,N) xy[i].second=i;

    unionFind uf(N);
    rep(i,N){
        rep(j,N){
            if(xy[i].first.first>xy[j].first.first && xy[i].first.second>xy[j].first.second){
                uf.unite(i,j);
            }
        }
    }

    rep(i,N) cout<<uf.size(i)<<endl;
}

// template<class T, T (*op)(T ,T), T (*e)()> struct segmentTree{
//     int n;
//     std::vector<T> v;
//     segmentTree() : segmentTree(0){}
//     segmentTree(int n_){
//         n=1;
//         while(n<n_) n*=2;
//         v=std::vector<T>(2*n-1,e());
//     }
//     ~segmentTree(){}
//     void set(int k, T a){
//         k+=n-1;
//         v[k]=a;
//         while(k>0){
//             k=(k-1)/2;
//             v[k]=op(v[k*2+1],v[k*2+2]);
//         }
//     }
//     T get(int k){return v[k+n-1];}
//     T sum(int l, int r){return sum(l,r,0,0,n);}     // [l,r) 半開区間に注意
//     T sum(int l, int r, int k, int a, int b){
//         if(b<=l || r<=a) return e();
//         if(l<=a && b<=r) return v[k];
//         T vl=sum(l,r,k*2+1,a,(a+b)/2);
//         T vr=sum(l,r,k*2+2,(a+b)/2,b);
//         return op(vl,vr);
//     }
// };
// int op(int a, int b){return a+b;}
// int e(){return 0;}

// int N;
// pair<P,int> xy[200000];

// int main(){
//     cin>>N;
//     rep(i,N) cin>>xy[i].first.first>>xy[i].first.second;
//     rep(i,N) xy[i].second=i;

//     sort(xy,xy+N);

//     segmentTree<int,op,e> st1(N);
//     segmentTree<int,op,e> st2(N);
//     vector<int> ans(N,0);
//     rep(i,N){
//         st1.set(xy[i].first.second-1,1);
//         st2.set(xy[N-i-1].first.second-1,1);
//         rep(i,N) cout<<st1.get(i)<<' '; cout<<' ';
//         rep(i,N) cout<<st2.get(i)<<' '; cout<<endl;
//         ans[xy[i].second]+=st1.sum(0,xy[i].first.second);
//         ans[xy[N-i-1].second]+=st2.sum(xy[N-i-1].first.second,N);
//     }

//     rep(i,N) cout<<ans[i]<<endl;

//     return 0;
// }

// int N;
// pair<P,int> p[200000];

// int main(){
//     cin>>N;
//     rep(i,N) cin>>p[i].first.first>>p[i].first.second;
//     rep(i,N) p[i].second=i;

//     sort(p,p+N);

//     cout<<endl;
//     //rep(i,N) cout<<p[i].first.first<<' '<<p[i].first.second<<endl;

//     vector<P> ans(N);
//     int l=0;
//     int r=N-p[0].first.second+1;
//     ans[0].first=p[0].second;
//     ans[0].second=l+r;
//     cout<<p[0].first.first<<' '<<p[0].first.second;
//     cout<<"  "<<l<<' '<<r<<' '<<endl;
//     repn(i,N-1){
//         if(p[i-1].first.second<p[i].first.second){
//             l++;
//             r--;
//         }else{
//             int a=l, b=r;
//             l=
//             r=(N-p[i].first.second+1)-((p[i].first.first-1)-l);
//         }
//         cout<<p[i].first.first<<' '<<p[i].first.second;
//         cout<<"  "<<l<<' '<<r<<' '<<endl;
//         ans[i].first=p[i].second;
//         ans[i].second=l+r;
//     }

//     sort(ans.begin(),ans.end());

//     rep(i,N) cout<<ans[i].second<<endl;
// }