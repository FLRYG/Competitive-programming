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
    T query(int l, int r){return query(l,r,0,0,n);}
    T query(int l, int r, int k, int a, int b){
        if(b<=l || r<=a) return 0;
        if(l<=a && b<=r) return v[k];
        T vl=query(l,r,k*2+1,a,(a+b)/2);
        T vr=query(l,r,k*2+2,(a+b)/2,b);
        return op(vl,vr);
    }
};

int op(int a, int b){return a^b;}
int e(){return 0;}

int N,Q;
int A[300000];

int main(){
    cin>>N>>Q;
    rep(i,N) cin>>A[i];

    segmentTree<int,op,e> st(N);
    rep(i,N) st.set(i,A[i]);
    int T,X,Y;
    vector<int> ans;
    while(Q--){
        cin>>T>>X>>Y;
        X--;
        if(T==1){
            A[X]^=Y;
            st.set(X,A[X]);
        }else{
            ans.push_back(st.query(X,Y));
        }
    }

    repr(e,ans) cout<<e<<endl;
    
    return 0;
}