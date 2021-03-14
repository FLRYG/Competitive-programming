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
typedef pair<ll,ll> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=998244353;

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

ll H,W;
ll h1,w1,h2,w2;
ll cntB;
vector<ll> m; 

ll f(ll cntA){
    if(cntA==0){
        return 1;
    }
    if(m[cntA]!=0) return m[cntA];
    ll res=0;
    rep(i,cntA){
        res+=1+f(i)*cntA%MOD*mpow(cntA+cntB,MOD-2)%MOD;
        res%=MOD;
    }
    m[cntA]=res;
    return res;
}

int main(){
    cin>>H>>W;
    cin>>h1>>w1>>h2>>w2;

    cntB=abs(h1-h2)+abs(w1-w2);
    ll A=(H-1)+(W-1)-cntB;
    m=vector<ll>(A+1,0);
    // cout<<A<<' '<<cntB<<endl;

    cout<<f(A)<<endl;

    ll B=abs(h1-h2)+abs(w1-w2);
    ll A=(H-1)+(W-1)-cntB;
    vector<ll> dp(A+1,0);
    dp[0]=1;
    repn(i,A){
        ll x=i*(i+1)%MOD;
        dp[i]=1+dp[i-1]*
    }
    
    return 0;
}