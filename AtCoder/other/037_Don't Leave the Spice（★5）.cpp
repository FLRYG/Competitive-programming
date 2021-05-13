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

using T=ll;
template<class T, T (*op)(T ,T), T (*e)()> struct segmentTree{
    int n;
    std::vector<T> v;
    segmentTree() : segmentTree(0){}
    segmentTree(int _n){
        n=1;
        while(n<_n) n*=2;
        v=std::vector<T>(2*n-1,e());
    }
    void set(int k, T a){
        k+=n-1;
        v[k]=a;
        while(k>0){
            k=(k-1)/2;
            v[k]=op(v[k*2+1],v[k*2+2]);
        }
    }
    T get(int k){ return v[k+n-1]; }
    T query(int l, int r){ return query(l,r,0,0,n); }     // [l,r) 半開区間に注意
    T query(int l, int r, int k, int a, int b){
        if(b<=l || r<=a) return e();
        if(l<=a && b<=r) return v[k];
        T vl=query(l,r,k*2+1,a,(a+b)/2);
        T vr=query(l,r,k*2+2,(a+b)/2,b);
        return op(vl,vr);
    }
};
T op(T a, T b){ return max(a,b); } 
T e(){ return -1; }

ll W,N;
ll L[501];
ll R[501];
ll V[501];

int main(){
    cin>>W>>N;
    repn(i,N) cin>>L[i]>>R[i]>>V[i];

    segmentTree<T,op,e> dp(W+1);
    dp.set(0,0);
    repn(i,N){
        segmentTree<T,op,e> st(W+1);
        st.set(0,0);
        repn(j,W){
            if(j>=L[i]){
                ll x=dp.query(max(0LL,j-R[i]),j-L[i]+1);
                if(x!=-1) st.set(j,max(dp.get(j),x+V[i]));
                else st.set(j,dp.get(j));
            }else{
                st.set(j,dp.get(j));
            }
        }
        dp=st;
        // cout<<i; rep(j,W+1) cout<<' '<<dp.get(j); cout<<endl;
    }

    ll ans=dp.get(W);
    if(ans==0) ans=-1;

    cout<<ans<<endl;
    
    return 0;
}