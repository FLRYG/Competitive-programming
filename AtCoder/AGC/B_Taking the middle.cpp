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
// typedef pair<ll,ll> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
ll V[400000];

int main(){
    cin>>N;
    rep(i,2*N) cin>>V[i];

    ll ans=0;
    rep(i,N) ans+=max(V[i],V[2*N-1-i]);

    cout<<ans<<endl;

    return 0;
}

// template<class T, T (*op)(T ,T), T (*e)()> struct segmentTree{
//     int n;
//     std::vector<T> v;
//     segmentTree() : segmentTree(0){}
//     segmentTree(int _n){
//         n=1;
//         while(n<_n) n*=2;
//         v=std::vector<T>(2*n-1,e());
//     }
//     ~segmentTree(){}
//     void set(int k, T a){
//         k+=n-1;
//         v[k]=a;
//         while(k>0){
//             k=(k-1)/2;
//             v[k]=op(v[k*2+1],v[k*2+2]);
//         }
//     }
//     T get(int k){return v[k+n-1];}
//     const T& operator[](std::size_t n) const& { return v[n]; }
//     T& operator[](std::size_t n) & { return v[n]; }
//     T query(int l, int r){return query(l,r,0,0,n);}     // [l,r) 半開区間に注意
//     T query(int l, int r, int k, int a, int b){
//         if(b<=l || r<=a) return e();
//         if(l<=a && b<=r) return v[k];
//         T vl=query(l,r,k*2+1,a,(a+b)/2);
//         T vr=query(l,r,k*2+2,(a+b)/2,b);
//         return op(vl,vr);
//     }
// };
// ll op(ll a, ll b){ return max(a,b); }
// ll e(){ return -1; }

// ll N;

// int main(){
//     cin>>N;
//     segmentTree<ll,op,e> V(2*N);
//     rep(i,2*N) cin>>V[i];

//     map<int,int> deqid;
//     rep(i,2*N) deqid[V[i]];
//     int k=0;
//     repr(e,deqid) e.second=k++;

//     vector<deque<int>> deq(deqid.size());
//     rep(i,2*N) deq[deqid[V[i]]].push_back(i);

//     int l=N-1, r=N;
//     ll ans=0;
//     rep(i,N){
//         while(V[l]==-1) l--;
//         while(V[r]==-1) r++;
//         if(V[l]<V[r]){
//             ll v=V.query(r,2*N);
//             ans+=v;
//             int k=deq[deqid[v]].back();
//             deq[deqid[v]].pop_back();
//             V[k]=-1;
//         }else if(V[l]>V[r]){
//             ll v=V.query(0,l+1);
//             ans+=v;
//             int k=deq[deqid[v]].front();
//             deq[deqid[v]].pop_front();
//             V[k]=-1;
//         }else{
//             ll v1=V.query(r,2*N);
//             ll v2=V.query(0,l+1);
//             if(v1>v2){

//             }
//         }
//     }
    
//     return 0;
// }