#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template<class T, T (*op)(T ,T), T (*e)()> struct segmentTree{
    int n;
    std::vector<T> v;
    segmentTree() : segmentTree(0){}
    segmentTree(int _n){
        n=1;
        while(n<_n) n*=2;
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

//------------------------------------------------------------------

int op(int a, int b){ return min(a,b); }
int e(){ return 2147483647; }

int main(){
    int N,Q;
    cin>>N>>Q;
    
    segmentTree<int,op,e> st(N);
    while(Q--){
        int c,x,y;
        cin>>c>>x>>y;
        if(c==0) st.set(x,y);
        else cout<<st.query(x,y+1)<<endl;
    }
}