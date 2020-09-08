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
ll const MOD=998244353;

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

ll N,M,K;

int main(){
    cin>>N>>M>>K;

    ll ans=0;
    ll comb=1;
    rep(i,K+1){
        ans+=M*mpow(M-1,N-1-i)%MOD*comb%MOD;
        ans%=MOD;
        comb*=(N-1-i)*mpow(i+1,MOD-2)%MOD;
        comb%=MOD;
    }

    cout<<ans<<endl;
}