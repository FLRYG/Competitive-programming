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
    T sum(int l, int r){return sum(l,r,0,0,n);}
    T sum(int l, int r, int k, int a, int b){
        if(b<=l || r<=a) return 0;
        if(l<=a && b<=r) return v[k];
        int vl=sum(l,r,k*2+1,a,(a+b)/2);
        int vr=sum(l,r,k*2+2,(a+b)/2,b);
        return op(vl,vr);
    }
};
ll op(ll a, ll b){return a+b;}
ll e(){return 0;}

int N;
int a[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];
    segmentTree<ll,op,e> st1(N);
    segmentTree<ll,op,e> st2(N);
    rep(i,N) st1.set(i,a[i]);
    rep(i,N) st2.set(i,a[i]);

    ll cnt1=0, cnt2=0;
    rep(i,N){
        if(i&1){
            if(st1.sum(0,i+1)<=0){
                cnt1+=abs(st1.sum(0,i+1)-1);
                st1.set(i,1);
            }
            if(st2.sum(0,i+1)>=0){
                cnt2+=abs(st2.sum(0,i+1)-1);
                st2.set(i,-1);
            }
            // if(a[i]>=0) cnt2+=a[i]+1;
        }else{
            if(st1.sum(0,i+1)>=0){
                cnt1+=abs(st1.sum(0,i+1)-1);
                st1.set(i,-1);
            }
            if(st2.sum(0,i+1)<=0){
                cnt2+=abs(st2.sum(0,i+1)-1);
                st2.set(i,1);
            }
            // if(a[i]>=0) cnt1+=a[i]+1;
            // if(a[i]<=0) cnt2+=1-a[i];
        }
    }
    cout<<cnt1<<' '<<cnt2<<endl;

    // for(int i=N-1;i>=0;i--){
    //     if(i&1){
    //         if(a[i]<=0) cnt1+=1-a[i];
    //         if(a[i]>=0) cnt2+=a[i]+1;
    //     }else{
    //         if(a[i]>=0) cnt1+=a[i]+1;
    //         if(a[i]<=0) cnt2+=1-a[i];
    //     }
    // }

    cout<<min(cnt1,cnt2)<<endl;
}

// int N;
// int a[100000];

// int main(){
//     cin>>N;
//     rep(i,N) cin>>a[i];

//     ll ans=0;
//     ll d=0;
//     if(a[0]==0){
//         if(a[1]<0){
//             a[0]++;
//             d++;
//         }else{
//             a[0]--;
//             d--;
//         }
//         ans++;
//     }

//     rep(i,N-1) a[i+1]+=a[i];

//     rep(i,N-1){

//     }
// }