#include <vector>

struct segmentTree{
    int n;
    std::vector<int> v;
    segmentTree() : segmentTree(0){}
    segmentTree(int n_){
        n=1;
        while(n<n_) n*=2;
        v=std::vector(2*n-1,0);
    }
    ~segmentTree(){}
    void set(int k, int a){
        k+=n-1;
        v[k]=a;
        while(k>0){
            k=(k-1)/2;
            v[k]=v[k*2+1]+v[k*2+2];
        }
    }
    int query(int l, int r){return query(l,r,0,0,n);}
    int query(int l, int r, int k, int a, int b){
        if(b<=l || r<=a) return 0;
        if(l<=a && b<=r) return v[k];
        int vl=query(l,r,k*2+1,a,(a+b)/2);
        int vr=query(l,r,k*2+2,(a+b)/2,r);
        return vl+vr;
    }
};
