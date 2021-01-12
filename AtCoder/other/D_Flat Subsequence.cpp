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
    T get(int k){return v[k+n-1];}
    int query(int l, int r){return query(l,r,0,0,n);}
    int query(int l, int r, int k, int a, int b){
        if(b<=l || r<=a) return 0;
        if(l<=a && b<=r) return v[k];
        int vl=query(l,r,k*2+1,a,(a+b)/2);
        int vr=query(l,r,k*2+2,(a+b)/2,b);
        return op(vl,vr);
    }
};
int op(int a, int b){return max(a,b);}
int e(){return 0;}

int N,K;
int A[300000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    vector<int> cnt(300002);
    segmentTree<int,op,e> st(300001);
    int ans=0;
    for(int i=N-1;i>=0;i--){
        int cnt=1;
        cnt+=st.query(max(0,A[i]-K),min(300001,A[i]+K+1));
        ans=max(ans,cnt);
        st.set(A[i],max(cnt,st.get(A[i])));
    }

    cout<<ans<<endl;

    return 0;
}

// int N,K;
// int A[300000];

// int main(){
//     cin>>N>>K;
//     rep(i,N) cin>>A[i];

//     vector<int> cnt(300002);
//     rep(i,N){
//         int l,r;
//         l=max(A[i]-K,0);
//         r=min(A[i]+K+1,300001);
//         cnt[l]++;
//         cnt[r]--;
//     }
//     repn(i,300000){
//         cnt[i]+=cnt[i-1];
//     }
//     repn(i,20){
//         cout<<i<<' '<<cnt[i]<<endl;
//     }

//     int ans=0;
//     rep(i,300002){
//         ans=max(ans,cnt[i]);
//     }

//     cout<<ans<<endl;
// }