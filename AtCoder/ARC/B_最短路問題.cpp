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

int N;
ll A[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    if(A[0]!=0){
        cout<<0<<endl;
        return 0;
    }

    vector<ll> cnt(N,0);
    rep(i,N) cnt[A[i]]++;
    if(cnt[0]>1){
        cout<<0<<endl;
        return 0;
    }

    ll maxi=0;
    rep(i,N) maxi=max(maxi,A[i]);

    ll ans=1;
    rep(i,maxi){
        ans*=mpow((mpow(2,cnt[i])-1),cnt[i+1])%MOD*mpow(2,cnt[i+1]*(cnt[i+1]-1)/2)%MOD;
        ans%=MOD;
    }

    cout<<ans<<endl;
    
    return 0;
}