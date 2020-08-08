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

ll N;
ll A[100000];
ll cnt[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    rep(i,N) cnt[A[i]]++;
    bool flag=true;
    for(int i=(~N&1);i<N;i+=2){
        if(i==0 && cnt[i]!=1){
            flag=false;
            break;
        }else if(i!=0 && cnt[i]!=2){
            flag=false;
            break;
        }
    }

    ll ans;
    if(flag) ans=mpow(2,N/2);
    else ans=0;

    cout<<ans<<endl;
}