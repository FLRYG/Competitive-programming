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

using T=int;
template<class T, T (*op)(T ,T), T (*e)()> struct segmentTree{
    int n;
    std::vector<T> v;
    segmentTree() : segmentTree(0){}
    segmentTree(int _n){
        n=1;
        while(n<_n) n*=2;
        v=std::vector<T>(2*n-1,e());
    }
    // segmentTree(vector<T> _v){
    //     n=1;
    //     while(n<_n) n*=2;
    //     data.resize(2*n-1);
    //     for(int i=0; i<_v.size(); i++) data[N-1+i]=_v[i];
    //     for(int n-2; i>=0; i--) data[i]=data[i*2+1]+data[i*2+2];
    // }
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
T op(T a, T b){ return a+b; }
T e(){ return 0; }

string S;

int main(){
    cin>>S;
    int N=S.size();
    vector<int> v(N,0);
    rep(i,N) if(S[i]=='1') v[i]=1;

    int l=1, r=S.size()+1;
    while(r-l>1){
        int k=(l+r)/2;
        vector<int> sv=v;
        vector<int> sum(N+1+k,0);
        rep(i,N-k+1){
            sum[i+1]+=sum[i];
            sv[i]+=sum[i+1];
            sv[i]&=1;
            if(sv[i]){
                sum[i+1]++;
                sum[i+1+k]--;
                sv[i]=0;
            }
        }
        string s;
        rep(i,k) s+=sv[N-k+i]==0:
        bool flag=false;
        string zer="", one('1',k);
        rep(i,k+1){
            if(zer=)
        } 
    }

    return 0;
}