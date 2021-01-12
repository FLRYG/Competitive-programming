#include <vector>

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
    T sum(int l, int r){return sum(l,r,0,0,n);}
    T sum(int l, int r, int k, int a, int b){
        if(b<=l || r<=a) return 0;
        if(l<=a && b<=r) return v[k];
        int vl=sum(l,r,k*2+1,a,(a+b)/2);
        int vr=sum(l,r,k*2+2,(a+b)/2,b);
        return op(vl,vr);
    }
};
int op(int a, int b){}
int e(){}

// template<class T, T (*op)(T ,T), T (*e)()> struct segmentTree{
//     int n;
//     std::vector<T> dat1;
//     std::vector<T> dat2;
//     segmentTree() : segmentTree(0){}
//     segmentTree(int n_){
//         n=1;
//         while(n<n_) n*=2;
//         dat1=std::vector<T>(2*n-1,e());
//         dat2=std::vector<T>(2*n-1,e());
//     }
//     ~segmentTree(){}
//     void set(int k, T a){
//         k+=n-1;
//         dat1[k]=a;
//         while(k>0){
//             k=(k-1)/2;
//             dat1[k]=op(dat1[k*2+1],dat1[k*2+2]);
//         }
//     }
//     T get(int k){return dat1[k+n-1];}
//     T sum(int l, int r){return sum(l,r,0,0,n);}
//     T sum(int l, int r, int k, int a, int b){
//         if(b<=l || r<=a) return 0;
//         if(l<=a && b<=r) return dat1[k];
//         int vl=sum(l,r,k*2+1,a,(a+b)/2);
//         int vr=sum(l,r,k*2+2,(a+b)/2,b);
//         return op(vl,vr);
//     }
//     void add(int l, int r, T x){add(l,r,x,0,0,n)}
//     void add(int l, int r, T x, int k, int a, int b){
//         if(a<=l && r<=b) dat1[k]=op(dat1[k],x);
//         else if(a<r && l<b){
//             dat2[k]=op(dat2[k],(min(r,b)-max(l,a)))
//         }
//     }
// };
// int op(int a, int b){}
// int e(){}
