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

ll N;
ll A[2000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    vector<ll> frac(N+1,0);
    frac[0]=1;
    repn(i,N) frac[i]=i*frac[i-1]%MOD;

    ll ans=1;
    rep(i,N){
        if(A[i]!=-1) continue;
        ll l=i-1, r;
        while(A[i]==-1 && i<N) i++;
        r=i;
        ll k=r-l-1, m=A[r]-A[l];
        ll res=1;
        rep(j,k){
            res*=m+k-j;
            res%=MOD;
        }
        res*=mpow(frac[k],MOD-2);
        res%=MOD;
        ans*=res;
        ans%=MOD;
    }

    cout<<ans<<endl;
    
    return 0;
}