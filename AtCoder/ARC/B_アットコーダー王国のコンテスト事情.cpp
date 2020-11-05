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
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
typedef long double ld;

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
ll T[10000];
ll cnt[10001];

int main(){
    cin>>N;
    rep(i,N) cin>>T[i];

    sort(T,T+N);

    ll ans1=0, ans2=1;
    rep(i,N){
        cnt[T[i]]++;
    }
    repn(i,10000){
        ans2*=mfrac(cnt[i]);
        ans2%=MOD;
    }

    repn(i,N-1){
        T[i]+=T[i-1];
    }
    rep(i,N) ans1+=T[i];

    cout<<ans1<<'\n'<<ans2<<endl;
}