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

template<class T, T (*op)(T ,T), T (*e)()> struct segmentTree{
    int n;
    std::vector<T> v;
    segmentTree() : segmentTree(0){}
    segmentTree(int n_){
        n=1;
        while(n<n_) n*=2;
        v=std::vector<T>(2*n-1,e());
    }
    ~segmentTree(){}
    void set(int k, T a){
        k+=n-1;
        v[k]=a;
        while(k>0){
            k=(k-1)/2;
            v[k]=op(v[k*2+1],v[k*2+2]);
        }
    }
    T get(int k){return v[k+n-1];}
    T sum(int l, int r){return sum(l,r,0,0,n);}     // [l,r) 半開区間に注意
    T sum(int l, int r, int k, int a, int b){
        if(b<=l || r<=a) return e();
        if(l<=a && b<=r) return v[k];
        T vl=sum(l,r,k*2+1,a,(a+b)/2);
        T vr=sum(l,r,k*2+2,(a+b)/2,b);
        return op(vl,vr);
    }
};
ll op(ll a, ll b){ return a+b; }
ll e(){ return 0; }

ll H,W,M;

int main(){
    cin>>H>>W>>M;
    vector<ll> GX(H+1,W+1);
    vector<ll> GY(W+1,H+1);
    rep(i,M){
        ll x,y;
        cin>>x>>y;
        GX[x]=min(GX[x],y);
        GY[y]=min(GY[y],x);
    }
    
    vector<vector<ll>> invGY(H+2,vector<ll>(0));
    repn(j,W) invGY[GY[j]].push_back(j);

    segmentTree<ll,op,e> st(W+1);
    for(ll j=1;j<GX[1];j++) st.set(j,1);

    ll ans=0;
    repn(i,GY[1]-1) ans+=GX[i]-1;
    repn(j,GX[1]-1) ans+=GY[j]-1;
    repn(i,GY[1]-1){
        repr(j,invGY[i]) st.set(j,0);
        ans-=st.sum(1,GX[i]);
    }

    cout<<ans<<endl;

    return 0;
}

// ll H,W,M;

// int main(){
//     cin>>H>>W>>M;
//     vector<int> Y(W+1,H+1);
//     rep(i,M){
//         int x,y;
//         cin>>x>>y;
//         Y[y]=min(Y[y],x);
//     }

//     vector<ll> cnt(H+1,0);
//     repn(j,W) cnt[Y[j]]++;

//     ll ans=0;
//     for(int i=Y[1]+1;i<=H;i++){
//         cnt[i]+=cnt[i-1];
//     }
//     repn(i,H){
//         ans+=cnt[i];
//     }
//     ans=H*W-ans;

//     cout<<ans<<endl;

//     return 0;
// }