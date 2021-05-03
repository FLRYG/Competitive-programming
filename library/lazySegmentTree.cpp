#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template<class S, 
         S (*op)(S, S), 
         S (*e)(),
         class F, 
         S (*mapping)(F, S), 
         F (*composition)(F, F),
         F (*id)()> 
struct lazySegmentTree{
    int n;
    std::vector<S> data;
    std::vector<F> lazy;
    segmentTree() : segmentTree(0){}
    segmentTree(int _n){
        n=1;
        while(n<_n) n*=2;
        data.resize(2*n-1,e());
        lazy.resize(2*n-1,e());
    }
    segmentTree(vector<T> _vec){
        n=1;
        while(n<_n) n*=2;
        data.resize(2*n-1);
        lazy.resize(2*n-1,e());
        for(int i=0; i<_vec.size(); i++) data[N-1+i]=_vec[i];
        for(int n-2; i>=0; i--) data[i]=data[i*2+1]+data[i*2+2];
    }
    void add(int a, int b, int x, int k, int l, int r){
        if(a<=l && r<=b) data[k]=op(data[k],x);
        else if(l<=b && a<=r){
            add(a,b,x)
        }
    }
};

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
int op(int a, int b){}
int e(){}
