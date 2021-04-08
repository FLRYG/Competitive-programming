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

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

ll mfrac(ll n){
    if(n==0) return 1;
    else return n*mfrac(n-1)%MOD;
}

ll mperm(ll n,ll r){
    ll res=1;
    for(ll i=0;i<r;i++) res=res*(n-i)%MOD;
    return res;
}

ll mcomb(ll n,ll r){
    if(r>n-r) r=n-r;
    ll res=mperm(n,r);
    return res*mpow(mfrac(r),MOD-2)%MOD;
}

ll H,W,A,B;

int main(){
    cin>>H>>W>>A>>B;

    ll comb1=1;
    ll comb2=mpow(mfrac(H-1),MOD-2)*mpow(mfrac(W-1-B),MOD-2)%MOD;
    repn(i,H-1+W-1-B) comb2=comb2*i%MOD;

    ll ans=0;
    rep(i,H-A){
        // ans=(ans+mcomb(i+B,B)*mcomb(H-1-i+W-1-B,H-1-i)%MOD)%MOD;
        ans=(ans+comb1*comb2%MOD)%MOD;
        comb1=comb1*(B+i)%MOD*mpow(i+1,MOD-2)%MOD;
        comb2=comb2*(H-1-i)%MOD*mpow(H-1-i+W-1-B,MOD-2)%MOD;
    }

    cout<<ans<<endl;
    
    return 0;
}