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
    segmentTree(int _n, int x=e()){
        n=1;
        while(n<_n) n*=2;
        v=std::vector<T>(2*n-1,x);
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
int op(int a, int b){ return a+b; }
int e(){ return 0; }

int Q;

int main(){
    cin>>Q;

    segmentTree<int,op,e> st(200001,0);
    vector<int> ans;
    while(Q--){
        int T,X;
        cin>>T>>X;
        if(T==1){
            st.set(X,1);
        }else{
            int l=0, r=200001;
            while(r-l>1){
                int m=(l+r)/2;
                if(st.query(0,m)<X) l=m;
                else r=m;
            }
            ans.push_back(l);
            st.set(l,0);
        }
    }

    repr(e,ans) cout<<e<<endl;
    
    return 0;
}