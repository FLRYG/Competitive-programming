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

ll N,M;

int main(){
    cin>>N>>M;

    map<ll,ll> cnt;
    ll m=M;
    for(ll i=2;i*i<=M;i++){
        while(m%i==0){
            m/=i;
            cnt[i]++;
        }
    }
    if(m>1) cnt[m]++;

    vector<ll> frac(100101,0);
    frac[0]=1;
    repn(i,100100) frac[i]=frac[i-1]*i%MOD;

    ll ans=1;
    repr(e,cnt){
        ans*=frac[N-1+e.second]*mpow(frac[N-1],MOD-2)%MOD*mpow(frac[e.second],MOD-2)%MOD;
        ans%=MOD;
    }

    cout<<ans<<endl;
    
    return 0;
}