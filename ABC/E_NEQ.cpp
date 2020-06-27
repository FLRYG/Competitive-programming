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

const ll MOD=1'000'000'007;

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

ll N,M;

int main(){
    cin>>N>>M;

    ll an, an_1=1, an_2=0;
    if(N==1) an=an_2;
    if(N==2) an=an_1;
    if(N>=3){
        for(int n=3;n<=N;n++){
            an=(n-1)*(an_1+an_2)%MOD;
            an_2=an_1;
            an_1=an;
        }
    }
    //cout<<an<<endl;
    
    ll sum=1;
    ll c=1;
    ll d=1;
    ll x=1;
    repn(i,min(N-1,M-N)){
        c*=N-i+1;
        d*=i;
        x*=(M-N-i+1);
        c%=MOD;
        d%=MOD;
        x%=MOD;
        sum+=c*mpow(d,MOD-2)%MOD*x;
        sum%=MOD;
    }
    //cout<<sum<<endl;
    ll sum2=0;
    if(N<=M-N) sum2=mperm(M-N,N);

    ll ans=mperm(M,N)%MOD*(an*sum%MOD+sum2)%MOD%MOD;

    cout<<ans<<endl;
}