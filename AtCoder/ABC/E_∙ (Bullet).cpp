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
typedef pair<ll,pair<ll,ll>> P;

const ll MOD=1'000'000'007;

template<class T>T gcd(T a, T b){return b?gcd(b,a%b):a;}

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

ll N;
map<P,ll> m;

int main(){
    cin>>N;
    rep(i,N){
        ll a,b;
        cin>>a>>b;
        ll g=gcd(a,b);
        a/=g;
        b/=g;
        ll sign=a^b?-1:(a==0 && b==0)?0:1;
        P p(sign,pair<ll,ll>(a,b));
        m[p]++;
    }

    ll ans=mpow(2,N);
    repr(e,m){
        if(e.first.first>0){
            ll cnt1=e.second;
            ll cnt2=m[P(-1,pair<ll,ll>(e.first.second.second,e.first.second.first))];
            
        }
    }
    if(ans<0) ans+=MOD;

    cout<<ans<<endl;
}