#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

const ll MOD=1'000'000'007;

ll mpow(ll x,ll n){
    if(n==0) return 1;
    if(n%2==1) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2);
}

ll mfrac(ll n){
    if(n==0) return 1;
    else return n*mfrac(n-1)%MOD;
}

ll mperm(ll n,ll r){
    ll res=1;
    for(ll i=0;i<r;i++) res=res*(n-i)%MOD;
    return res%MOD;
}

ll mcomb(ll n,ll r){
    if(r>n-r) r=n-r;
    ll res=mperm(n,r);
    return res*mpow(mfrac(r),MOD-2)%MOD;
}

ll N,K;

int main(){
    cin>>N>>K;

    for(ll i=1;i<=K;i++){
        if(i>N-K+1){
            cout<<0<<endl;
            continue;
        }

        ll ans=mcomb(N-K+1,i)*mcomb(K-1,i-1)%MOD;

        //cout<<i<<':'<<ans<<' '<<mcomb(N-K+1,i)<<' '<<mcomb(K-1,i-1)<<endl;
        cout<<ans<<endl;
    }
}