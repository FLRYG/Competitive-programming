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
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll mpow(ll x, ll n){
    if(n==0) return 1;
    if(n&1) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

ll N;
ll A[10000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    vector<ll> v(1000001);
    for(ll i=1000000;i>=2;i--){
        for(ll j=i;j<=1000000;j+=i){
            v[j]=i;
        }
    }

    vector<ll> cnt(1000001);
    rep(i,N){
        ll a=A[i];
        map<ll,ll> m;
        while(a>1){
            m[v[a]]++;
            a/=v[a];
        }
        repr(e,m){
            cnt[e.first]=max(cnt[e.first],e.second);
        }
    }

    ll sum=1;
    rep(i,1000001){
        if(cnt[i]>0){
            //cout<<i<<' '<<cnt[i]<<endl;
            sum*=mpow(i,cnt[i]);
            sum%=MOD;
        }
    }
    //cout<<sum<<endl;

    ll ans=0;
    rep(i,N){
        ans+=sum*mpow(A[i],MOD-2)%MOD;
        ans%=MOD;
    }
    if(ans<0) ans+=MOD;

    cout<<ans<<endl;
}