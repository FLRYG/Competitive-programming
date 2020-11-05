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
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

ll N,K;
ll A[100000];

ll frac[100001];
ll inv[100001];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    sort(A,A+N);

    frac[0]=1;
    repn(i,N){
        frac[i]=frac[i-1]*i%MOD;
    }
    inv[0]=1;
    repn(i,N){
        inv[i]=mpow(frac[i],MOD-2);
    }

    ll ans=0;
    rep(i,N){
        if(i>=K-1){
            ans+=A[i]*frac[i]%MOD*inv[i-(K-1)]%MOD*inv[K-1]%MOD;
        }
        if(N-i-1>=K-1){
            ans-=A[i]*frac[N-i-1]%MOD*inv[(N-i-1)-(K-1)]%MOD*inv[K-1]%MOD;
        }
        ans%=MOD;
    }
    ans%=MOD;

    cout<<ans<<endl;
}