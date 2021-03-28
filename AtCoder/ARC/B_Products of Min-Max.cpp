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
ll const MOD=998244353;

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

ll N;
ll A[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    sort(A,A+N);

    vector<ll> sum(N+1,0);
    repn(i,N-1){
        sum[i+1]=sum[i]+A[i]*mpow(2,i-1)%MOD;
        sum[i+1]%=MOD;
    }

    ll ans=0;
    repn(i,N){
        ans+=A[i-1]*(sum[N]-sum[i])%MOD*mpow(mpow(2,i-1),MOD-2)%MOD;
        ans%=MOD;
        ans+=A[i-1]*A[i-1];
        ans%=MOD;
    }
    if(ans<0) ans+=MOD;

    cout<<ans<<endl;
    
    return 0;
}