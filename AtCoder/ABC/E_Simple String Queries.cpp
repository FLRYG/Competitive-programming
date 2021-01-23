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

template<class T, T (*op)(T& ,T&), T (*e)()> struct segmentTree{
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
        if(b<=l || r<=a) return e();
        if(l<=a && b<=r) return v[k];
        T vl=sum(l,r,k*2+1,a,(a+b)/2);
        T vr=sum(l,r,k*2+2,(a+b)/2,b);
        return op(vl,vr);
    }
};
vector<int> op(vector<int>& a, vector<int>& b){
    vector<int> res(a.size());
    rep(i,a.size()) res[i]=a[i]|b[i];
    return res;
}
vector<int> e(){return vector<int>(26,0);}

int N,Q;
string S;

int main(){
    cin>>N>>S>>Q;

    segmentTree<vector<int>,op,e> st(N);
    vector<int> v(26,0);
    rep(i,N){
        v[S[i]-'a']++;
        st.set(i,v);
        v[S[i]-'a']--;
    }

    int q,i,l,r;
    char c;
    vector<int> ans;
    while(Q--){
        cin>>q;
        if(q==1){
            cin>>i>>c;
            vector<int> v(26,0);
            v[c-'a']++;
            st.set(i-1,v);
        }else{
            cin>>l>>r;
            vector<int> v=st.sum(l-1,r);
            int res=0;
            rep(i,v.size()) if(v[i]) res++;
            ans.push_back(res);
        }
    }

    rep(i,ans.size()) cout<<ans[i]<<endl;
    
    return 0;
}