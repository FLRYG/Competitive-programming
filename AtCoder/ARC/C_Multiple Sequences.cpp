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

ll N,M;

int main(){
    cin>>N>>M;

    vector<ll> p(M+1,0);
    p[1]=M;
    for(int i=2;i<=M;i++) p[i]=M/i-M/(i-1);

    vector<ll> cnt(M+1);
    repn(i,M){
        for(int j=i;j<=M;j+=i) cnt[j]++;
    }

    ll ans=0;
    repn(m,M){
        cout<<m<<' '<<cnt[m]<<endl;
        ans+=mpow(cnt[m],N-1);
    }

    cout<<ans<<endl;
    
    return 0;
}